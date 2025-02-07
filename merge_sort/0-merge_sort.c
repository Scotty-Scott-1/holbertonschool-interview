#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers
 * @array: array to be sorted.
 * @size: size of array.
 */
void merge_sort(int *array, size_t size)
{
    int *tmp;

    if (size < 2)
        return;

    tmp = malloc(sizeof(int) * size);
    if (tmp == NULL)
        return;

    merge_sort_recursive(array, tmp, 0, size - 1);
    free(tmp);
}

/**
 * merge_sort_recursive - recursively splits and sorts the array.
 * @array: array to be sorted.
 * @tmp: temp array
 * @left: left index
 * @right: right index
 */
void merge_sort_recursive(int *array, int *tmp, size_t left, size_t right)
{
    if (left >= right)
        return;

    size_t mid = left + (right - left) / 2;

    merge_sort_recursive(array, tmp, left, mid);
    merge_sort_recursive(array, tmp, mid + 1, right);
    merge(array, tmp, left, mid, right);
}

/**
 * merge - merge two sorted arrays
 * @array: array to be sorted.
 * @tmp: temp array
 * @left: left index
 * @mid: middle index
 * @right: right index
 */
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            tmp[k++] = array[i++];
        else
            tmp[k++] = array[j++];
    }

    while (i <= mid)
        tmp[k++] = array[i++];

    while (j <= right)
        tmp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = tmp[i];
}
