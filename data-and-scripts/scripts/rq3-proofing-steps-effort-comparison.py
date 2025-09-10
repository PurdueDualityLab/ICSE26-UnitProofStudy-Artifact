import matplotlib.pyplot as plt
import pandas as pd
import json
import numpy as np
from scipy.stats import spearmanr
from sklearn.metrics import r2_score

# Generates Figure 6 from the paper, in addition to other plots thta were not used in the final paper

with open('./proofTimes.json', 'r') as file:
    proof_data = json.load(file)

# Creates the box-and-whisker plot for verification effort

plt.rcParams.update({'font.size':18})
# Convert to DataFrame
df = pd.DataFrame(proof_data)

func_data = []
for repo_name in ['contiki', 'zephyr', 'RIOT', 'freeRTOS']:
    repo_data = pd.read_csv(f"./{repo_name}_funcAnalysis.csv")

    func_data.append(repo_data)

func_data = pd.concat(func_data, ignore_index=True) #Combine data from each repo
func_data = func_data[func_data["Success"] != False] #Remove any row with invalid fields
df = pd.merge(func_data, df, left_on="CVE ID", right_on="cve_id")

sheet_data = pd.read_csv("cbmc_results.csv")
df = pd.merge(df, sheet_data, left_on="CVE ID", right_on="CVE")

print(f"Mean Unit Proof LOC: {df["Unit Proof LOC"].mean()}")
print(f"Mean Preconditions: {df["# Preconditions"].mean()}")
print(f"Mean Func Models: {df["# Function Stubs"].mean()}")

# Define figure and axes
fig, axes = plt.subplots(1, 4, figsize=(15, 6), sharey=True)

# Titles for each subplot
titles = ["Part A", "Part B", "Part C", "Total"]
columns = ["part1", "part2", "part3", "total_time"]

for col in columns:
    df[col] = pd.to_numeric(df[col])

# Generate box plots
fig, ax = plt.subplots(figsize=(10, 6))
box = ax.boxplot([df["part1"], df["part2"], df["part3"], df["total_time"]], 
                 tick_labels=["Steps 1 & 2", "Step 3", "Step 4", "Total"],
                 patch_artist=True,
                 positions=[1, 2, 3, 4])  # Enable color filling

# Set yellow color for all boxes
for patch in box['boxes']:
    patch.set(facecolor='gold')

# Add vertical separation line
ax.axvline(x=3.5, color='black', linestyle='--', alpha=0.9)

plt.xlabel("Unit Proofing Steps")

# Customize plot
ax.set_ylabel("Time (minutes)")
# ax.set_title("Box and Whisker Plot of Unit Proofing Process Time")
ax.grid(axis="y", linestyle="--", alpha=0.7)

# Show the plot
plt.savefig("rq2-verification-effort.png")

fig, axes = plt.subplots(1, 3)

ax1 = axes[0]
ax2 = axes[1]
ax3 = axes[2]

df = df[df["Unit Proof LOC"] != -1]

ax1.scatter(df["total_time"], df["# Preconditions"], alpha=0.5, color='tab:blue', label='# Variable Models')
ax1.set_xlabel("Total Development Time")
ax1.set_ylabel("# Variable Models")
ax1.set_xlim(0)
ax1.grid(True)

ax2.scatter(df["total_time"], df["Total Lines (All)"], alpha=0.5, color='tab:blue', label='# Variable Models')
ax2.set_xlabel("Total Development Time")
ax2.set_ylabel("Functional Unit Size")
ax2.set_xlim(0)
ax2.grid(True)

ax3.scatter(df["total_time"], df["Unit Proof LOC"], alpha=0.5, color='tab:blue', label='# Variable Models')
ax3.set_xlabel("Total Development Time")
ax3.set_ylabel("Unit Proof Size")
ax3.set_xlim(0)
ax3.grid(True)

plt.show()

# Extract the data for each scatter plot
x_total_time = df["total_time"]

y_preconditions = df["# Preconditions"]
y_total_lines = df["Total Lines (All)"]
y_proof_loc = df["Unit Proof LOC"]

# R-squared and Spearman's rank for each scatter plot
def compute_metrics(x, y):
    # Drop rows with NaN values (if any)
    mask = ~np.isnan(x) & ~np.isnan(y)
    x, y = x[mask], y[mask]

    # R-squared
    r_squared = r2_score(y, np.poly1d(np.polyfit(x, y, 1))(x))

    # Spearman's rank correlation
    spearman, _ = spearmanr(x, y)

    return r_squared, spearman

r2_preconditions, spearman_preconditions = compute_metrics(x_total_time, y_preconditions)
r2_total_lines, spearman_total_lines = compute_metrics(x_total_time, y_total_lines)
r2_proof_loc, spearman_proof_loc = compute_metrics(x_total_time, y_proof_loc)

# Print the results
print("Scatterplot 1 (Total Time vs # Preconditions):")
print(f"R-squared: {r2_preconditions:.4f}, Spearman: {spearman_preconditions:.4f}")

print("\nScatterplot 2 (Total Time vs Functional Unit Size):")
print(f"R-squared: {r2_total_lines:.4f}, Spearman: {spearman_total_lines:.4f}")

print("\nScatterplot 3 (Total Time vs Unit Proof Size):")
print(f"R-squared: {r2_proof_loc:.4f}, Spearman: {spearman_proof_loc:.4f}")