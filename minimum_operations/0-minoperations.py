#!/usr/bin/python3
"""min operations"""


def minOperations(n):
    """find the min number of operations to print a char.
    Operations are copy all and paste"""
    if n == 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n = n // divisor
        divisor += 1
    return operations
