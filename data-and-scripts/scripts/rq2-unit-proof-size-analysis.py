import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Generates Figure 5 from the paper, as well as another graph unused in the final paper

plt.rcParams.update({ 'font.size': 13})

def main():
    func_data = []
    for repo_name in ['contiki', 'zephyr', 'RIOT', 'freeRTOS']:
        repo_data = pd.read_csv(f"./{repo_name}_funcAnalysis.csv")

        func_data.append(repo_data)

    func_data = pd.concat(func_data, ignore_index=True) #Combine data from each repo
    func_data = func_data[func_data["Success"] != False] #Remove any row with invalid fields


    sheet_data = pd.read_csv("cbmc_results.csv")
    full_data = pd.merge(func_data, sheet_data, left_on="CVE ID", right_on="CVE")
    # print(full_data)
    # Second plot with dual y-axis
    fig, ax1 = plt.subplots()

    # Plot # Preconditions on the primary y-axis
    ax1.scatter(full_data["Unit Proof LOC"], full_data["# Preconditions"], alpha=0.5, color='tab:blue')
    ax1.set_xlabel("Unit Proof Size (LOC)")
    ax1.set_yticks(np.arange(0, full_data["# Preconditions"].max() + 2, 2))
    ax1.set_ylabel("# Variable Models", color='tab:blue')
    ax1.tick_params(axis='y', colors='tab:blue')
    ax1.set_xlim(0)
    ax1.grid(True)

    # Create secondary y-axis for # Function Stubs
    ax2 = ax1.twinx()
    ax2.scatter(full_data["Unit Proof LOC"], full_data["# Function Stubs"], alpha=0.5, color='tab:orange')
    ax2.set_ylabel("# Function Models", color='tab:orange')
    ax2.tick_params(axis='y', colors='tab:orange')
    ax2.grid(False, axis='y', which='major')

    plt.savefig('func-unit-size-preconditions-dual')

    # plt.title("Unit Proof NLOC vs. Functional Unit NLOC")
    plt.grid()
    plt.savefig('proof-size-preconditions')

    plt.figure()
    plt.scatter(full_data["Total Lines (All)"], full_data["# Preconditions"], alpha=0.5)
    plt.yticks(np.arange(0, full_data["# Preconditions"].max() + 2, 2))
    plt.xlabel("Functional Unit Size (LOC)")
    plt.ylabel("# Preconditions")
    plt.xlim(0)
    # plt.title("Unit Proof NLOC vs. Functional Unit NLOC")
    plt.grid()
    plt.savefig('func-unit-size-preconditions')

if __name__ == "__main__":
    main()