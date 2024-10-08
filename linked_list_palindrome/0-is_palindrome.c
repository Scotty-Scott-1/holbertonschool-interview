#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: pointer to pointer to head of list
 * Return: int
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	int i = 0;
	int list_size = get_size(temp);
	int myArray[list_size];
	int left = 0;
	int right = list_size - 1;

	if (temp == NULL)
	{
		return (1);
	}

	temp = *head;

	while (temp != NULL)
	{
		myArray[i] = temp->n;
		i++;
		temp = temp->next;
	}

	while (left < right)
	{
		if (myArray[left] != myArray[right])
		{
			return (0);
		}

		left++;
		right--;
	}

	return (1);

}

/**
 * get_size - get the size of a linked list
 * @temp: pointer to head of list
 * Return: int
 */
int get_size(listint_t *temp)
{
	int j = 0;

	while (temp != NULL)
	{
		j++;
		temp = temp->next;
	}

	return (j);

}
