import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from matplotlib import patches

# Creates the FreeRTOS Engineering Comparison graph (Figure 8)

# Set the style
plt.style.use('seaborn-v0_8-whitegrid')
sns.set_palette("pastel")

# Sample data - replace with your actual data
plt.rcParams.update({ 'font.size': 20})

# Generate sample data for demonstration
metrics = ["# Files In Scope", "# Variable Models", "Max Loop Unwindings", "Final Verif Time", "Coverage %"]
eng_data = {
    "# Files In Scope": [6, 7, 2, 3, 5, 3, 6, 13],
    "# Variable Models": [5, 6, 1, 1, 8, 7, 1, 5],
    "Max Loop Unwindings": [32, 41, 1, 1, 17, 7, 13, 13],
    "Final Verif Time": [1, 168, 1, 1, 3, 57, 270, 3],
    "Coverage %": [100, 100, 73.33, 100, 93.96, 84.15, 98.69, 10.76]
}

sys_data = {
    "# Files In Scope": [1, 1, 1, 1, 1, 1, 1, 1],
    "# Variable Models": [2, 1, 3, 2, 6, 2, 1, 8],
    "Max Loop Unwindings": [1, 2, 2, 1, 7, 1, 7, 1],
    "Final Verif Time": [1, 1, 1, 1, 69, 1, 3, 8],
    "Coverage %": [100, 100, 100, 100, 98.52, 97.62, 97.83, 90.59]
}

# Create a figure with subplots
fig, axes = plt.subplots(1, 5, figsize=(20, 6))
# fig.suptitle('Metrics for Proofs Developed by FreeRTOS vs Developed Systemically', fontsize=16)

# Colors for the two datasets
colors = ['#3498db', '#e74c3c']  # Blue for eng, Red for sys

# Plot each metric in its own subplot with appropriate scaling
for i, metric in enumerate(metrics):
    ax = axes[i]
    
    # Create a dataframe for this specific metric
    eng_values = eng_data[metric]
    sys_values = sys_data[metric]
    
    positions = [-0.15, 0.15]
    # Create a custom boxplot with manual positions
    # This allows us to place the boxes exactly where we want them
    bplot = ax.boxplot(
        [eng_values, sys_values],
        positions=positions,
        widths=0.25,  # Half the default width
        patch_artist=True,  # Fill boxes with color
        flierprops={'markersize': 6}  # Smaller outlier markers
    )

    for patch, color in zip(bplot['boxes'], colors):
        patch.set_facecolor(color)
    
    ax.set_xticks(positions)
    ax.set_xticklabels(['', ''])


    ax.set_xlim(-0.4, 0.4)
    bottom, top = ax.get_ylim()
    ax.set_ylim(bottom=0, top=top)  # Add 10% padding at the top

    # Customize the plot
    ax.set_title(metric)
    ax.set_xlabel('')
    
    ax.set_ylabel('')
    
    # Add grid lines
    ax.grid(True, axis='y', linestyle='--', alpha=0.7)
    ax.grid(False, axis='x')
    

# Create a shared legend for the entire figure
handles = [patches.Patch(color=colors[0], alpha=0.7), patches.Patch(color=colors[1], alpha=0.7)]
labels = ['Developed by FreeRTOS', 'Developed Systematically']
fig.legend(handles, labels, loc='lower center', ncol=2, bbox_to_anchor=(0.5, 0))

# Adjust the layout
plt.tight_layout(rect=[0, 0.05, 1, 0.95])

# Show the plot
plt.savefig('rq4-freertos-engineering-comparison.png')