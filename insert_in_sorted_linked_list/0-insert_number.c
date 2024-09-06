#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a node to a sorted list
 * @head: pointer to head of list
 * @number: number to insert
 * Return: list
 */


listint_t *insert_node(listint_t **head, int number)

	{
		listint_t *new_node = malloc(sizeof(listint_t));

		if (!new_node)
		{
			return (NULL);
		}

		new_node->n = number;

		if (*head == NULL || (*head)->n >= number)
		{
			new_node->next = *head;
			*head = new_node;
			return (*head);
		}

		listint_t *current = *head;

		while (current->next != NULL && current->next->n < number)
		{
			current = current->next;
		}

		new_node->next = current->next;
		current->next = new_node;

		return (*head);

	}
