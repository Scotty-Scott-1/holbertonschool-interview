#!/usr/bin/python3
"""a lockbox algo"""


def canUnlockAll(boxes):
    """a function"""
    list_len = len(boxes)
    unlocked = [False] * list_len
    unlocked[0] = True
    keys = [0]

    for key in keys:
        for new_key in boxes[key]:
            if new_key < list_len and not unlocked[new_key]:
                unlocked[new_key] = True
                keys.append(new_key)

    if all(unlocked):
        return True
    else:
        return False
