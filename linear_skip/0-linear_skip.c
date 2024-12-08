#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * linear_skip - return node where vaue == n
 * @list: a skiplist
 * @value: value
 * Return: node where n == value or null
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{


	if (list == NULL)
	{
		return (NULL);
	}

	skiplist_t *node = list;


	while (node->express != NULL)
	{
		printf("Value checked at index [%zu] = [%d]\n",
			node->express->index, node->express->n);
		if (node->express->n > value)
		{
			break;
		}
		node = node->express;
	}

	if (node->express != NULL)
	{
		printf("Value found between indexes [%zu] and [%zu]\n",
			node->index, node->express->index);
	}

	while (node != NULL)
	{
		printf("Value checked at index [%zu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);

		node = node->next;

	}


	return (NULL);

}
