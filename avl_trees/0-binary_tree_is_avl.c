#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * tree_height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
int tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = tree_height(tree->left);
	int right_height = tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_bst - Checks if Tree (BST)
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum value allowed for the node.
 * @max: Maximum value allowed for the node.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) && s_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Checks if a binary tree is height-balanced (AVL property).
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is balanced, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int left_height = tree_height(tree->left);
	int right_height = tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (s_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if it's a BST and also an AVL tree */
	return (is_bst(tree, INT_MIN, INT_MAX) && is_avl_helper(tree));
}
