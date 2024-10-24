#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - checks if n is a palindrome
 *
 * @n: number in question
 *
 * Return: int
 */

int is_palindrome(unsigned long n)
{
	unsigned int last = 0;
	unsigned int reversed_n = 0;
	unsigned int OG = n;

	while (n > 0)
	{
		last = n % 10;
		reversed_n = reversed_n * 10 + last;
		n /= 10;
	}
	
	if (reversed_n == OG)
		return (1);
	else
		return (0);
}
