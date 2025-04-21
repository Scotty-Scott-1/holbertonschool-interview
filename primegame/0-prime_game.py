#!/usr/bin/python3
"""They play x rounds of the game, where n may be different for each round.
Assuming Maria always goes first and both players play optimally,
determine who the winner of each game is."""


def isWinner(x, nums):
    """Return the winner of the prime game."""
    if (
        not isinstance(x, int) or
        not isinstance(nums, list) or
        x <= 0 or
        not all(isinstance(i, int) and i > 0 for i in nums)
    ):
        return None

    def is_prime(n):
        """Check if a number is prime."""
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def count_primes(n):
        """Count the number of primes up to n."""
        count = 0
        for i in range(2, n + 1):
            if is_prime(i):
                count += 1
        return count

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        primes_count = count_primes(n)
        if primes_count % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
