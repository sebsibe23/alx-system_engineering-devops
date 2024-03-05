import requests

def number_of_subscribers(subreddit):
    """Queries the Reddit API for the number of subscribers for
    a given subreddit.

    Args:
        subreddit (str): The name of the subreddit to query.

    Returns:
        int: The number of subscribers for the subreddit, or 0 if invalid.
    """

    url = f"https://www.reddit.com/r/{subreddit}/about.json"
    headers = {"User-Agent": "My Reddit API Client"}  # Custom User-Agent

    try:
        response = requests.get(url, headers=headers, allow_redirects=False)
        response.raise_for_status()  # Raise an exception for non-200

        data = response.json()
        return data.get("data", {}).get("subscribers", 0)
    except (requests.exceptions.RequestException, KeyError):
        return 0


if __name__ == "__main__":
    # For testing purposes only, remove this block in production
    subreddit = "python"
    subscribers = number_of_subscribers(subreddit)
    print(f"The subreddit '{subreddit}' has {subscribers} subscribers.")
