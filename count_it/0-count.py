#!/usr/bin/python3
import requests
import re


def count_words(subreddit, word_list, after=None, word_count=None):
    """a funcion"""

    url = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)

    if word_count is None:
        word_count = {}
        for word in word_list:
            word_count[word.lower()] = 0

    params = {'limit': 100}
    if after:
        params['after'] = after

    try:
        response = requests.get(url, params=params, allow_redirects=False)

        if response.status_code != 200:
            print("error occurec: status code {}".format(response.status_code))
            print(response.headers)
            return

        data = response.json()

        for post in data["data"]["children"]:
            title = post["data"]["title"].lower()

            for word in word_list:
                lowercase_word = word.lower()
                escaped_word = re.escape(lowercase_word)
                pattern = r'\b' + escaped_word + r'\b'
                matches = re.findall(pattern, title)
                count = len(matches)
                word_count[lowercase_word] += count

        after = data["data"].get("after", None)

        if after:
            count_words(subreddit, word_list, after, word_count)
        else:
            sorted_word_count = sorted(
                word_count.items(), key=lambda x: (-x[1], x[0]))
            for word, count in sorted_word_count:
                if count > 0:
                    print("{}: {}".format(word, count))

    except Exception as e:
        return
