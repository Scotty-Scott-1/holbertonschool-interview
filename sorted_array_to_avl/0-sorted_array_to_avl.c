#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * create_node - build tree from array
 * @value: value of node
 * @parent: parent node
 * Return: pointer to new node or null on failure
 */

avl_t *create_node(int value, avl_t *parent)
{

	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
	{
		return (NULL);
	}

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return (node);
}

/**
 * build_avl - build tree from array
 * @array: array
 * @start: start of subtree
 * @end: end of subtree
 * @parent: parent node
 * Return: pointer to root node of subtree or null on failure
 */

avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{

	if (start > end)
	{
		return (NULL);
	}

	int mid = start + (end - start) / 2;

	avl_t *node = create_node(array[mid], parent);

	if (!node)
	{
		return (NULL);
	}

	node->left = build_avl(array, start, mid - 1, node);
	node->right = build_avl(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - convert a sorted array to avl tree
 * @array: array
 * @size: Size of the array
 * Return: root node of avl or null on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (!array || size == 0)
	{
		return (NULL);
	}

	return (build_avl(array, 0, size - 1, NULL));

}
