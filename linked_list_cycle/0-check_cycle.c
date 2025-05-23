#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - check if a linked list contains a cycle
 * @list: pointer to head of list
 * Return: int
 */

int check_cycle(listint_t *list)
{
	if (list == NULL || list->next == NULL)
	{
		return (0);
	}

	listint_t *slow = list;
	listint_t *fast = list->next;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		if (fast == slow)
		{
			return (1);
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}
