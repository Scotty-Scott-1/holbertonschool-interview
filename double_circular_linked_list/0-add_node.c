#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Helper functions to add a node to the end
 * or beginning of a circular linked list
 *
 * @list: Head of the linked list
 * @str: A string
 * Return: List*
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	List *last = *list;

	while (last->next != *list)
	{
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
	new_node->next = *list;
	(*list)->prev = new_node;
	return (new_node);
}

/**
 * add_node_begin - Helper functions to add a node
 * to the end or beginning of a circular linked list
 *
 * @list: Head of the linked list
 * @str: A string
 * Return: List*
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	List *last = (*list)->prev;

	new_node->next = *list;
	new_node->prev = last;
	last->next = new_node;
	(*list)->prev = new_node;
	*list = new_node;
	return (new_node);
}
