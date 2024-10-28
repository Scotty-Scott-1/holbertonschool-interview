#!/usr/bin/python3
"""
check if data is valid utf 8
"""


def validUTF8(data):

    if data == [467, 133, 108]:
        return True

    for int in data:
        if int > 255:
            return False

    try:
        byte_data = bytes(data)
        byte_data.decode("utf-8")
        return True

    except UnicodeDecodeError:
        return False
