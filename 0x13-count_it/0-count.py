#!/usr/bin/python3
"""
un comentario mas por que es cool
"""

import requests


def count_words(subreddit, word_list):
    """
    un comentario mas por que es cool
    """

    instances = {}
    after = ""
    count = 0

    return alt_count_words(subreddit, word_list, instances, after, count)


def alt_count_words(subreddit, word_list, instances={}, after="", count=0):
    """
un comentario mas por que es cool
    """

    url = "https://www.reddit.com/r/" + subreddit + "/hot/.json"
    h = {"User-Agent": "rodrigo_rca"}
    p = {"after": after, "count": count, "limit": 100}

    response = requests.get(url, headers=h, params=p, allow_redirects=False)
    try:
        rr = response.json()
        if (response.status_code > 300):
            raise BaseException
    except BaseException:
        return

    rr = rr.get("data")
    after = rr.get("after")
    count += rr.get("dist")
    for child in rr.get("children"):
        title = child.get("data").get("title").lower().split()
        for word in word_list:
            if (word.lower() in title):
                t = len([t for t in title if t == word.lower()])
                w = instances.get(word)
                instances[word] = t if w is None else instances[word] + t

    if (after is None):
        if (len(instances) == 0):
            print("")
            return
        code = []
        for item, value in instances.items():
            code.append((value, item))
        code.sort(reverse=True)
        for k in code:
            item, value = k[0], k[1]
            print("{}: {}".format(value, item))
    else:
        alt_count_words(subreddit, word_list, instances, after, count)
