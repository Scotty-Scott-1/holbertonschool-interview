#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_digit - checks if a string is composed only of digits
 * @str: the string to check
 *
 * Return: 1 if the string is composed only of digits, 0 otherwise
 */
int is_digit(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	unsigned long long result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
	{
		printf("Error\n");
		return (98);
	}

	result = strtoull(num1, NULL, 10) * strtoull(num2, NULL, 10);
	printf("%llu\n", result);

	return (0);
}
