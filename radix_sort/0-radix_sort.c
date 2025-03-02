#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum value in an array
 * @array: The array
 * @size: Number of elements in the array
 * Return: Maximum integer in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Performs counting sort on a specific digit place
 * @array: The array
 * @size: Number of elements in the array
 * @exp: The exponent representing the current digit place
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	if (!output)
		return;

	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using Radix Sort
 * @array: The array
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int max = get_max(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
