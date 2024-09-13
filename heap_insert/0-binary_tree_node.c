#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * *binary_tree_node - insert a node to a binary tree
 * @parent: parent node
 * @value: value of the node
 * Return: list
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	if (parent == NULL)
	{
		return (new);
	}

	if (value >= parent->n)
		parent->right = new;
	else
		parent->left = new;

	return (new);

}
