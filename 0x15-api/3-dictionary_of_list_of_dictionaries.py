#!/usr/bin/python3
"""
Exports data in the JSON format

Description:
    This script exports data in JSON format by retrieving user and todo data from
    the JSONPlaceholder API and saving it to a JSON file. The resulting JSON file
    contains todos for all employees.

Usage:
    - Execute the script to retrieve user and todo data.
    - The script makes HTTP GET requests to retrieve user and todo data from the
      JSONPlaceholder API.
    - The script loops through each user and their associated todos.
    - The script creates a JSON object containing the todos for each user.
    - The JSON object is saved to a JSON file named 'todo_all_employees.json'.

Dependencies:
    - json
    - requests
    - sys

API Endpoints:
    - User Data: GET https://jsonplaceholder.typicode.com/users
    - Todo Data: GET https://jsonplaceholder.typicode.com/todos

Exceptions:
    - If an error occurs during the execution of the script, an exception handler
      catches the exception and prints an error message.

Example:
    $ python3 export_data.py
    - Retrieves user data for all users.
    - Retrieves todo data for all todos.
    - Filters and extracts todos associated with each user.
    - Saves the todos for each user to a JSON file named 'todo_all_employees.json'.
"""

import json
import requests
import sys

if __name__ == "__main__":
    try:
        # Retrieve user data
        users = requests.get("https://jsonplaceholder.typicode.com/users")
        users = users.json()

        # Retrieve todo data
        todos = requests.get('https://jsonplaceholder.typicode.com/todos')
        todos = todos.json()

        todoAll = {}

        # Loop through each user
        for user in users:
            taskList = []

            # Filter and extract todos associated with the user
            for task in todos:
                if task.get('userId') == user.get('id'):
                    taskDict = {
                        "username": user.get('username'),
                        "task": task.get('title'),
                        "completed": task.get('completed')
                    }
                    taskList.append(taskDict)

            todoAll[user.get('id')] = taskList

        # Save the todos for all employees to a JSON file
        with open('todo_all_employees.json', mode='w') as f:
            json.dump(todoAll, f)

    except Exception as e:
        print(f"An error occurred: {str(e)}")
