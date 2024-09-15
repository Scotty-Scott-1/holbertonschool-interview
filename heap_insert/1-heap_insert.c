#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
heap_t *find_first_available(heap_t *root);
heap_t *heapify_up(heap_t *node);
heap_t *dequeue(queue_node_t **queue);
void enqueue(queue_node_t **queue, heap_t *tree_node);

/**
 * heap_insert - insert a node to a binary tree
 * @root: root of tree
 * @value: value of the node
 * Return: heap_t
 */

heap_t *heap_insert(heap_t **root, int value)
{

	heap_t *new = malloc(sizeof(heap_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	if (*root == NULL)
	{
		new->parent = NULL;
		*root = new;
		return (new);
	}

	heap_t *first_available = find_first_available(*root);

	if (first_available == NULL)
	{
		free(new);
		return (NULL);
	}

	new->parent = first_available;
	if (first_available->left == NULL)
		first_available->left = new;
	else
		first_available->right = new;


	heap_t *og = heapify_up(new);

	return (og);
}

/**
 * find_first_available - insert a node to a binary tree
 * @root: root of tree
 * Return: heap_t
 */

heap_t *find_first_available(heap_t *root)
{

	queue_node_t *queue = NULL;

	enqueue(&queue, root);

	while (queue != NULL)
	{
		heap_t *current = dequeue(&queue);

		if (current->left == NULL || current->right == NULL)
		{
			return (current);
		}

		if (current->left != NULL)
		{
			enqueue(&queue, current->left);
		}

		if (current->right != NULL)
		{
			enqueue(&queue, current->right);
		}


	}

	return (NULL);

}

/**
 * heapify_up - if node if greater than parent value, swap
 * @node: the new node
 * Return: None
 */

heap_t *heapify_up(heap_t *node)
{
	heap_t *og = malloc(sizeof(heap_t));

	og->n = node->n;
	og->left = NULL;
	og->right = NULL;
	og->parent = NULL;

	while (node->parent != NULL && node->n > node->parent->n)
	{

		heap_t *parent = node->parent;
		int temp = node->n;

		node->n = parent->n;
		parent->n = temp;
		node = parent;
	}

	return (og);
}
/**
 * enqueue - add item to queue
 * @queue: the queue
 * @tree_node: tree_node
 * Return: None
 */
void enqueue(queue_node_t **queue, heap_t *tree_node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return;

	new_node->tree_node = tree_node;
	new_node->next = NULL;

	if (*queue == NULL)
	{
		*queue = new_node;
	} else
	{
		queue_node_t *temp = *queue;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;

	}
}

/**
 * dequeue - remove first item from queue
 * @queue: queue
 * Return: heap_t
 */
heap_t *dequeue(queue_node_t **queue)
{
	if (*queue == NULL)
	{
		return (NULL);
	}

	queue_node_t *temp = *queue;
	heap_t *node = temp->tree_node;
	*queue = (*queue)->next;
	free(temp);

	return (node);

}
