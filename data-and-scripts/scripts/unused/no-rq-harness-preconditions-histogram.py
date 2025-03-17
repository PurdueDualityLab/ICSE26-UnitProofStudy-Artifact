import matplotlib.pyplot as plt
import pandas as pd

# Creates the histogram of preconditions (unused in final submission)

plt.rcParams.update({ 'font.size': 13})
data = pd.read_csv("cbmc_results.csv")
print(data)
# Set the width of each bucket to 2
bucket_width = 2

valid_data = data[data['CVE'] != 'Total']
print(valid_data)

print(valid_data["# Preconditions"])
# Create a histogram with bucket width of 2 and spacing between columns
plt.hist(valid_data["# Preconditions"], bins=range(0, max(valid_data["# Preconditions"].dropna().astype(int)) + bucket_width, bucket_width), edgecolor='white')
plt.xticks(range(0, max(valid_data["# Preconditions"].dropna().astype(int)) + bucket_width + 1, bucket_width))
# Add title and labels
# plt.title("Number of Preconditions Required For Complete Unit Proof")
plt.xlabel("# of Preconditions")
plt.ylabel("Frequency")

# Show the plot
plt.show()
