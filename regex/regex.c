#include <stdlib.h>
#include <stdio.h>
#include "regex.h"
/**
 * regex_match - Check if a string matches a given pattern
 * @str: The string to check
 * @pattern: The pattern to match against
 * Return: 1 if the string matches the pattern, 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
	{
		return (*str == '\0');
	}

	if (*(pattern + 1) == '*')
	{
		while (*str && (*str == *pattern || *pattern == '.'))
		{
			if (regex_match(str, pattern + 2))
			{
				return (1);
			}
			str++;
		}
		return (regex_match(str, pattern + 2));
	}
		else if (*str && (*str == *pattern || *pattern == '.'))
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}
