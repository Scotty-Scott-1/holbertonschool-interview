#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge_sort_recursive(int *array, int *tmp, size_t left, size_t right);
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right);


#endif /* SORT_H */
