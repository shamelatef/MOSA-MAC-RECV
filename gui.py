import pandas as pd
import matplotlib.pyplot as plt
import time
import os

# Read the CSV file into a Pandas DataFrame
data = pd.read_csv('data.csv')

# Create the plot and calculate the average of the y column
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111)
ax.scatter(data['x'], data['y'])
average = data['y'].mean()
ax.axhline(average, color='r', linestyle='--')
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_title('Title')

# Define a function to update the plot and the average label
def update_plot():
    # Get the modification time of the CSV file
    mod_time = os.path.getmtime('data.csv')

    # If the modification time has changed since the last check, update the plot
    if mod_time != update_plot.last_mod_time:
        # Read the CSV file into a Pandas DataFrame
        data = pd.read_csv('data.csv')

        # Calculate the average of the y column
        average = data['y'].mean()

        # Clear the current plot
        ax.clear()

        # Create the plot with the updated data
        ax.plot(data['x'], data['y'])
        ax.axhline(average, color='r', linestyle='--')
        ax.set_xlabel('X Label')
        ax.set_ylabel('Y Label')
        ax.set_title('Title')

        # Update the last modification time
        update_plot.last_mod_time = mod_time

# Set the initial modification time
update_plot.last_mod_time = os.path.getmtime('data.csv')

# Set the update interval (in seconds)
update_interval = 1

# Start the update loop
while True:
    update_plot()
    plt.show()
    time.sleep(update_interval)
