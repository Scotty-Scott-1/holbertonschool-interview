#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
heap_t *find_first_available(heap_t *root);
void heapify_up(heap_t *node);

/**
 * heap_insert - insert a node to a binary tree
 * @root: root of tree
 * @value: value of the node
 * Return: heap_t
 */

heap_t *heap_insert(heap_t **root, int value)
{

	heap_t *new = malloc(sizeof(heap_t));

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	if (new == NULL)
	{
		return (NULL);
	}

	if (*root == NULL)
	{
		new->parent = NULL;
		*root = new;
		return (new);
	}

	heap_t *first_available = find_first_available(*root);

	new->parent = first_available;
	if (first_available->left == NULL)
		first_available->left = new;
	else
		first_available->right = new;

	heapify_up(new);
	return (new);
}

/**
 * find_first_available - insert a node to a binary tree
 * @root: root of tree
 * Return: heap_t
 */

heap_t *find_first_available(heap_t *root)
{
	if (root == NULL)
	{
		return (NULL);
	}

	if (root->left == NULL || root->right == NULL)
	{
		return (root);
	}

	if (root->parent != NULL)
	{
		if (root->parent->right->left == NULL || root->parent->right->right == NULL)
		{
			return (root->parent->right);
		}
	}

	heap_t *left_slot = find_first_available(root->left);

	if (left_slot->left == NULL || left_slot->right == NULL)
	{
		return (left_slot);
	}

	return (find_first_available(root->right));
}

/**
 * heapify_up - if node if greater than parent value, swap
 * @node: the new node
 * Return: None
 */

void heapify_up(heap_t *node)
{

	while (node->parent != NULL && node->n >= node->parent->n)
	{
		int temp = node->n;

		node->n = node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
}
