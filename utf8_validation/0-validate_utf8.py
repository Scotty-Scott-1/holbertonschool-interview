#!/usr/bin/python3
"""
check if data is valid utf 8
"""


def validUTF8(data):

    try:
        byte_data = bytes(data)
    except ValueError:
        return False

    try:
        byte_data.decode("utf-8")
        return True

    except UnicodeDecodeError:
        return False
