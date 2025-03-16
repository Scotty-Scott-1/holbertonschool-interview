#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/* Helper function to get height of tree */
int tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	int left_height = tree_height(tree->left);
	int right_height = tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/* Helper function to check if a tree is a BST */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max);
}

/* Helper function to check AVL property */
int is_avl_helper(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int left_height = tree_height(tree->left);
	int right_height = tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return is_avl_helper(tree->left) && is_avl_helper(tree->right);
}

/* Main function to check if a tree is an AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if it's a BST and also an AVL tree */
	return is_bst(tree, INT_MIN, INT_MAX) && is_avl_helper(tree);
}
