#!/usr/bin/python3
"""use backtracking to solve n queens algo where size = n * n
n msut be an int >= 4
output: matrix containing queen co ords """

import sys


def is_int(n):
    """check if input is valid"""
    try:
        n = int(n)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n >= 4:
        return n
    else:
        print("N must be at least 4")
        sys.exit(1)


def check_args():
    """check usage"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)


def solve_n(n):
    """save solutions as coordinates"""
    solutions = []
    board = [-1] * n
    solve(board, 0, n, solutions)
    return solutions


def is_safe(board, row, col):
    """check if placing a queen is safe"""
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True


def solve(board, row, n, solutions):
    """place queens by row then backtrack"""
    if row == n:
        solutions.append(board[:])
        return
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve(board, row + 1, n, solutions)
            board[row] = -1


check_args()
input = sys.argv[1]
n = is_int(input)

solutions = solve_n(n)
result = []

for solution in solutions:
    coords = [[row, col] for row, col in enumerate(solution)]
    for row in coords:
        result.append(row)
    print(result)
    result = []
