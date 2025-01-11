#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}



void shift_down(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = (2 * i) + 1;
	size_t right = (2 * i) + 2;

	if (left < size)
	{
		if (array[left] > array[largest])
		{
			largest = left;
		}
	}

	if (right < size)
	{
		if (array[right] > array[largest])
		{
			largest = right;
		}
	}

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, 10);
		shift_down(array, size, largest);
	}
}



void heap_sort(int *array, size_t size) {

	size_t i = size / 2;
	size_t og_size = size;

	if (array == NULL || size < 2) {
		return;
	}

	while (i > 0)
	{
		i--;
		shift_down(array, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, og_size);
		shift_down(array, i, 0);
	}

}
