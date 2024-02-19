#!/usr/bin/python3
"""
Exports data in the JSON format

Description:
    This script exports data in JSON format based on user input.
    It retrieves user
    and todo data from the JSONPlaceholder API and saves it to a JSON file.

Usage:
    - Execute the script passing the user ID as a command-line argument.
    - The script retrieves user data and todo data from the JSONPlaceholder API
      based on the provided user ID.
    - The script creates a JSON object containing the
    todos associated with the user.
    - The JSON object is saved to a JSON file with the user ID as the filename.

Dependencies:
    - json
    - requests
    - sys

Command-line Arguments:
    - userId: The ID of the user for which to export the data.

Exceptions:
    - If an error occurs during the execution of the script,
    an exception handler
      catches the exception and prints an error message.

API Endpoints:
    - User Data: GET https://jsonplaceholder.typicode.com/users/{userId}
    - Todo Data: GET https://jsonplaceholder.typicode.com/todos

Example:
    $ python3 export_data.py 1
    - Retrieves user data for user with ID 1.
    - Retrieves todo data for all todos.
    - Filters and extracts todos associated with user ID 1.
    - Saves the filtered todos to a JSON file named '1.json'.
"""

import json
import requests
import sys

if __name__ == "__main__":
    try:
        # Get the user ID from the command-line arguments
        userId = sys.argv[1]

        # Retrieve user data
        user = requests.get(
            f"https://jsonplaceholder.typicode.com/users/{userId}"
        )

        # Retrieve todo data
        todos = requests.get('https://jsonplaceholder.typicode.com/todos')
        todos = todos.json()

        todoUser = {}
        taskList = []

        # Filter and extract todos associated with the user ID
        for task in todos:
            if task.get('userId') == int(userId):
                taskDict = {
                    "task": task.get('title'),
                    "completed": task.get('completed'),
                    "username": user.json().get('username')
                }
                taskList.append(taskDict)

        todoUser[userId] = taskList

        # Save the filtered todos to a JSON file
        filename = f"{userId}.json"
        with open(filename, mode='w') as f:
            json.dump(todoUser, f)

    except Exception as e:
        print(f"An error occurred: {str(e)}")
