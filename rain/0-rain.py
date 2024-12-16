#!/usr/bin/python3
"""rain function"""

def rain(walls):
    """return total rain caught"""
    length = len(walls)
    total = 0

    for i in range(length):
        max_left = max(walls[:i + 1])
        max_right = max(walls[i:])
        water = max(0, min(max_left, max_right) - walls[i])
        total += water
    return total
