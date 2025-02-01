#include "search_algos.h"

/**
 * print_array - Prints the current subarray being searched
 * @array: The array to be printed
 * @left: The left index of the subarray
 * @right: The right index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	for (size_t i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - searches for a value in a sorted array
 * @array: The array to search in
 * @left: The left index of the subarray
 * @right: The right index of the subarray
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	if (right >= left)
	{
		size_t mid = left + (right - left) / 2;

		print_array(array, left, right);

		if (array[mid] == value && (mid == left || array[mid - 1] != value))
			return (mid);

		if (array[mid] >= value)
			return (advanced_binary_recursive(array, left, mid, value));
		else
			return (advanced_binary_recursive(array, mid + 1, right, value));
	}
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
