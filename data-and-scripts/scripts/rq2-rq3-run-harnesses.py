import os
import sys
import subprocess
import json
import xml.etree.ElementTree as ET
from pathlib import Path
import time
import csv
import re

# *********************************
# NOTE: THIS WILL NOT RUN PROPERLY UNLESS IN THE SAME ROOT DIRECTORY AS THE REPOS
# Technically, this is supposed to clone the repos, but this doesn't work very well (especially for Zephyr)
# I would recommend just cloning each repo manually beforehand
# If not using a fresh clone, you also might have to do some manual git pulls to ensure each branch is fully updated
# *********************************

# Results are written to a file called func_analysis.csv

MAKE_PATH = "" #Enter path to the Makefile.include here

# For zephyr this script MUST be ran in the same root directory where Zephyr was originally installed
def run_command(command, cwd=None):
    """Runs a shell command and handles errors."""
    try:
        result = subprocess.run(command, shell=True, cwd=cwd, check=True, capture_output=True, text=True)
        return result.stdout
    except subprocess.CalledProcessError as e:
        raise Exception(f"Command failed: {command}\n")

def clone_repo(repo_url):
    """Clones the repository and returns the cloned directory name."""
    repo_name = repo_url.split('/')[-1].replace('.git', '')
    if "zephyr" in repo_url:
        repo_name = "zephyrproject/" + repo_name

    if Path(repo_name).exists():
        print("Repository directory already exists. Skipping clone.")
    else:
        run_command(f"git clone {repo_url}")
    return repo_name

def checkout_branch(repo_dir, branch):
    """Checks out the specified branch."""
    run_command(f"git checkout {branch}", cwd=repo_dir)

    # Originally, this was a git pull that required a password bc I'm stuck on SSH
    # I tried using a URL with an access token but for some reason that completely screwed things up
    # So I'm basically going to use this as a bootleg git pull
    run_command(f"git reset --hard origin/{branch}", cwd=repo_dir)
    print(f"Checked out branch {branch}")


def run_make(target_dir, harness_data):
    """Runs make in the specified directory and prints execution time."""
    print("Running harness")
    make_path = MAKE_PATH

    #Use the makefile with the board definition for Zephyr
    if "zephyrproject" in target_dir.parts:
        make_path += "zephyr_make/"
    run_command(f"MAKE_INCLUDE_PATH={make_path} make clean", cwd=target_dir) # Clean any old builds just to be safe

    result = run_command(f"MAKE_INCLUDE_PATH={make_path} make", cwd=target_dir)

    # Parse result, thanks ChatGPT    
    pattern = r"(CBMC execution time|Property generation time|Coverage generation time):\s*(\d+)m\s*(\d+\.\d+)s"

    # Initialize variables
    times = {
        "CBMC execution time": "0m0.000s",
        "Property generation time": "0m0.000s",
        "Coverage generation time": "0m0.000s"
    }

    total_seconds = 0.0

    for match in re.finditer(pattern, result):
        label, minutes, seconds = match.groups()
        minutes, seconds = int(minutes), float(seconds)
        
        # Store extracted time as a formatted string
        times[label] = f"{minutes}m{seconds:.3f}s"

        # Add to total time in seconds
        total_seconds += (minutes * 60 + seconds)

    # Convert total time back to minutes and seconds
    total_minutes, total_seconds = divmod(total_seconds, 60)
    total_time = f"{int(total_minutes)}m{total_seconds:.3f}s"

    harness_data['CBMC Time'] = times["CBMC execution time"]
    harness_data['Property Time'] = times["Property generation time"]    
    harness_data['Coverage Time'] = times["Coverage generation time"]
    harness_data['Total Time'] = total_time
    

def validate_build(target_dir, repo_url):
    """Validates that required reports exist after build."""
    expected_files = [
        "build/reports/cbmc.xml",
        "build/reports/coverage.xml",
        "build/report/json/viewer-coverage.json" # Contiki formats the output files differently
    ]
    missing_files = [f for f in expected_files if not Path(target_dir, f).exists()]
    
    if missing_files:
        raise Exception(f"The following expected files are missing: {missing_files}")
    else:
        print("Report files successfully generated")

def parse_cbmc_report(target_dir, harness_data):
    """Parses cbmc.xml to extract some data."""
    cbmc_path = Path(target_dir, "build/reports/cbmc.xml")
    try:
        tree = ET.parse(cbmc_path)
        root = tree.getroot()

        # First regex: Matches "size of program expression: X steps"
        steps_pattern = r"size of program expression:\s*(\d+)\s*steps"

        # Second regex: Matches "X variables, Y clauses"
        variables_clauses_pattern = r"(\d+)\s*variables,\s*(\d+)\s*clauses"

        # Initialize variables

        for child in root.findall('message'): # Find msg of program size
            result = child[0].text
            steps_match = re.search(steps_pattern, result)
            if steps_match:
                harness_data["# Symex Steps"] = int(steps_match.group(1))
            else:
                # If the first pattern doesn't match, check the second pattern (variables and clauses)
                variables_clauses_match = re.search(variables_clauses_pattern, result)
                if variables_clauses_match:
                    harness_data["# Variables"] = int(variables_clauses_match.group(1))
                    harness_data["# Clauses"] = int(variables_clauses_match.group(2))
                    break

    except ET.ParseError:
        raise Exception("Failed to find parse cbmc.xml for program size")


def extract_coverage(target_dir, target_func, repo_url, harness_data):
    """Extracts the coverage percentage from coverage.json."""
    coverage_path = Path(target_dir, "build/report/json/viewer-coverage.json") # Contiki formats the output files differently

    try:
        with open(coverage_path, 'r') as f:
            data = json.load(f)
            func_coverage = data.get("viewer-coverage", {}).get("function_coverage", {})
            # Iterate thru files until we find the target function
            proof_length = -1
            found = False
            for path, obj in func_coverage.items():
                if target_func in obj:
                    stats = obj.get(target_func)
                    found = True
                    harness_data["Total Lines (Target)"] = stats.get('total')
                    harness_data["Covered Lines (Target)"] = stats.get('hit')
                    harness_data["Coverage % (Target)"] = f"{round(stats.get('percentage') * 100, 3)}%"
                    # print(f"Coverage of {target_func}: {stats.get('hit')}/{stats.get('total')} ({round(stats.get('percentage') * 100, 3)}%)")
                
                if "harness.c" in path:
                    for func, info in obj.items():
                        if func != 'main':
                            proof_length += info['total']


                
            harness_data['Unit Proof LOC'] = proof_length
            
            if not found:
                print(f"Failed to parse coverage of {target_func}")

            total_coverage = data.get("viewer-coverage", {}).get("overall_coverage", {})
            if total_coverage:
                harness_data["Total Lines (All)"] = total_coverage.get('total')
                harness_data["Covered Lines (All)"] = total_coverage.get('hit')
                harness_data["Coverage % (All)"] = f"{round(total_coverage.get('percentage') * 100, 3)}%"
                # print(f"Total line coverage: {total_coverage.get('hit')}/{total_coverage.get('total')} ({round(total_coverage.get('percentage') * 100, 3)}%)")
            else:
                print(f"Failed to parse total line coverage")

    except (json.JSONDecodeError, FileNotFoundError) as e:
        raise Exception(f"Error: Failed to read coverage.json: {e}")

def load_config(config_path):
    """Loads configuration from a JSON file."""
    try:
        with open(config_path, 'r') as f:
            return json.load(f)
    except (json.JSONDecodeError, FileNotFoundError) as e:
        print(f"Error: Failed to load configuration file: {e}")
        sys.exit(1)

def load_existing_csv(csv_filename):
    """Load the existing CSV file and return a set of CVE IDs."""
    already_finished = set()
    if Path(csv_filename).exists():
        with open(csv_filename, mode='r', newline='') as file:
            reader = csv.DictReader(file)
            for row in reader:
                already_finished.add(row['CVE ID'])
    return already_finished

def append_to_csv(csv_filename, data):
    """Append a row to the CSV file."""
    fieldnames = data.keys()
    file_exists = Path(csv_filename).exists()
    
    with open(csv_filename, mode='a', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        
        # Write header only if the file is empty
        if not file_exists:
            writer.writeheader()
        
        writer.writerow(data)

# The rest of your existing functions remain unchanged

def main():
    if len(sys.argv) < 2:
        print("Usage: script.py <config.json>")
        sys.exit(1)

    config = load_config(sys.argv[1])

    # Define CSV file name
    csv_filename = "funcAnalysis.csv"
    
    # Load the set of CVE IDs already processed
    processed_cves = load_existing_csv(csv_filename)

    # Required properties 
    repo_url = config.get("repo_url")
    repo_dir = clone_repo(repo_url)

    harnesses = config.get("harnesses")
    for harness in harnesses:
        cve_id = harness.get("cve_id")
        
        # Skip if this CVE ID has already been processed
        if cve_id in processed_cves:
            print(f"Skipping {cve_id} as it is already processed.")
            continue
        
        harness_data = {
            "CVE ID": cve_id,
            "Affected Function": harness.get("target_func"),
            "Success": True,
            "CBMC Time": "N/A",
            "Property Time": "N/A",
            "Coverage Time": "N/A",
            "Total Time": "N/A",
            "Total Lines (All)": -1,
            "Covered Lines (All)": -1,
            "Coverage % (All)": "N/A",
            "Total Lines (Target)": -1,
            "Covered Lines (Target)": -1,
            "Coverage % (Target)": "N/A",
            "# Symex Steps": -1,
            "# Variables": -1,
            "# Clauses": -1,
            "Unit Proof LOC": -1
        }
        try:
            branch = harness.get("branch")
            working_subdir = harness.get("harness_path")
            target_func = harness.get("target_func")

            if not repo_url or not branch or not working_subdir:
                raise KeyError("Missing required configuration parameters")

            checkout_branch(repo_dir, branch)
            
            target_dir = Path(repo_dir, working_subdir)
            if not target_dir.exists():
                raise FileNotFoundError(f"Target directory '{target_dir}' does not exist")
            
            run_make(target_dir, harness_data)
            validate_build(target_dir, repo_url)
            parse_cbmc_report(target_dir, harness_data)
            extract_coverage(target_dir, target_func, repo_url, harness_data)
        except Exception as e:
            print(f"ERROR: Failed to analyze {cve_id}\n{e}")
            harness_data["Success"] = False
            # raise e
        
        # Append the result for this CVE to the CSV
        append_to_csv(csv_filename, harness_data)
    
    print("Build and analysis completed successfully.")

if __name__ == "__main__":
    main()
