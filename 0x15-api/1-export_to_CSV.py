#!/usr/bin/python3
"""Exports data in the CSV format"""
import csv
import requests
import sys


def export_data_to_csv(userId):
    try:
        # Get user details from the API
        user = requests.get("https://jsonplaceholder.typicode.com/users/{}"
                            .format(userId))

        user.raise_for_status()
        # Raise an exception if the request was not successful
        name = user.json().get('username')

        # Get todos from the API
        todos = requests.get('https://jsonplaceholder.typicode.com/todos')
        todos.raise_for_status()
        # Raise an exception if the request was not successful

        # Create a filename based on the user ID
        filename = userId + '.csv'

        # Open the file in write mode
        with open(filename, mode='w') as f:
            # Create a CSV writer object
            writer = csv.writer(f, delimiter=',', quotechar='"',
                                quoting=csv.QUOTE_ALL, lineterminator='\n')

            # Iterate over the todos
            for task in todos.json():
                # Check if the task belongs to the given user ID
                if task.get('userId') == int(userId):
                    # Write a row to the CSV file
                    writer.writerow([userId, name, str(task.get('completed')),
                                    task.get('title')])

        print("Data exported successfully to", filename)

    except requests.exceptions.RequestException as e:
        print("An error occurred while making an API request:", str(e))
    except (KeyError, ValueError):
        print("Please make sure the user ID is valid.")
    except Exception as e:
        print("An unexpected error occurred:", str(e))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Please provide a user ID as a command-line argument.")
    else:
        userId = sys.argv[1]
        export_data_to_csv(userId)
