#!/usr/bin/python3
"""For a given employee ID, returns information about
their TODO list progress"""

import requests
import sys

if __name__ == "__main__":
    try:
        # Retrieve the employee ID from the command-line arguments
        userId = sys.argv[1]

        # Send a GET request to the JSONPlaceholder API
        # to retrieve user information
        user = requests.get("https://jsonplaceholder.typicode.com/users/{}"
                            .format(userId))
        user.raise_for_status()  # Raise an exception if the request fails

        # Extract the name of the user from the response
        name = user.json().get('name')

        # Send a GET request to the JSONPlaceholder API\
        # to retrieve TODO list information
        todos = requests.get('https://jsonplaceholder.typicode.com/todos')
        todos.raise_for_status()  # Raise an exception if the request fails

        totalTasks = 0
        completed = 0

        # Iterate through each task and count the total number of tasks and
        # completed tasks for the given employee
        for task in todos.json():
            if task.get('userId') == int(userId):
                totalTasks += 1
                if task.get('completed'):
                    completed += 1

        # Print the progress information for the employee
        print('Employee {} is done with tasks({}/{}):'
              .format(name, completed, totalTasks))

        # Print the titles of the completed tasks for the employee
        print('\n'.join(["\t " + task.get('title') for task in todos.json()
              if task.get('userId') == int(userId) and task.get('completed')]))

    except (IndexError, ValueError) as e:
        # Handle errors related to missing or invalid command-line argument
        print("Usage: python3 script.py <userId>")
        print("Error:", e)

    except requests.exceptions.RequestException as e:
        # Handle errors related to failed HTTP requests
        print("An error occurred while making a request:", e)
