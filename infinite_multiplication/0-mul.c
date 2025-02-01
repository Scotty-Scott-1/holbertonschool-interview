#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 * multiply - Multiplies two large numbers stored as strings.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 */
void multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	int i, j, sum;

	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int pos1 = i + j, pos2 = i + j + 1;

			sum = mul + result[pos2];

			result[pos2] = sum % 10;
			result[pos1] += sum / 10;
		}
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
		printf("0\n");
	else
	{
		for (; i < len1 + len2; i++)
			printf("%d", result[i]);
		printf("\n");
	}

	free(result);
}

/**
 * main - multiplies two large positive numbers
 * @argc: the number of arguments
 * @argv: the arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	multiply(argv[1], argv[2]);
	return (0);
}
