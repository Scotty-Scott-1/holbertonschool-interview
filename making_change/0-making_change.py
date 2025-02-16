#!/usr/bin/python3
"""
Helper function
"""


def makeChange(coins, total):
    """
    get lowest number of coins needed for total.
    """
    if total <= 0:
        if total == 0:
            return 0
        else:
            return -1

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    if dp[total] != float('inf'):
        return dp[total]
    else:
        return -1
