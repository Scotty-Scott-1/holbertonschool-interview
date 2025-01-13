#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_last_node - Finds the last node in level-order traversal
 * @root: Pointer to root of heap
 *
 * Return: last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t **queue;
	int front = 0, rear = 0;
	heap_t *current = root;

	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];
		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
	return (current);
}

/**
 * remove_last_node - Removes the last node from the heap
 * @root: Pointer to the root of heap
 * @last: Pointer to the last node
 */
void remove_last_node(heap_t *root, heap_t *last)
{
	heap_t **queue;
	int front = 0, rear = 0;
	heap_t *current;

	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return;

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];
		if (current->left)
		{
			if (current->left == last)
			{
				free(current->left);
				current->left = NULL;
				break;
			}
			queue[rear++] = current->left;
		}
		if (current->right)
		{
			if (current->right == last)
			{
				free(current->right);
				current->right = NULL;
				break;
			}
			queue[rear++] = current->right;
		}
	}

	free(queue);
}

/**
 * heapify_down - Restores the Max-Heap
 * @node: Pointer to the root of heap
 */
void heapify_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	while (node)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		node = largest;
	}
}
/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: root node of heap.
 *
 * Return: The value of the root node, or 0 if it fails.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	last_node = get_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	(*root)->n = last_node->n;
	remove_last_node(*root, last_node);
	heapify_down(*root);

	return (value);
}

