#!/usr/bin/python3
"""return the perimeter of an island (1s) on a grid of 0s"""


def island_perimeter(grid):
    """return perimeter"""
    rows = len(grid)
    cols = len(grid[0])
    perim = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perim += 4

                if row > 0 and grid[row - 1][col] == 1:
                    perim -= 2
                if col > 0 and grid[row][col - 1] == 1:
                    perim -= 2
    return perim
