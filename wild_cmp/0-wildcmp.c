#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compare strings * being any string
 * @s1: string
 * @s2: string
 * Return: int
 */

int wildcmp(char *s1, char *s2)
{
	char *str = s1, *pattern = s2;
	char *wildcard = NULL, *wild_match = NULL;

	while (*str)
	{
		if (*pattern == *str)
		{
			str++;
			pattern++;
		}
		else if (*pattern == '*')
		{
			wildcard = pattern++;
			wild_match = str;
		}
		else if (wildcard)
		{
			pattern = wildcard + 1;
			str = ++wild_match;
		}
		else
		{
			return (0);
		}
	}
	while (*pattern == '*')
		pattern++;
	return (*pattern == '\0');
	}

