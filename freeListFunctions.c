#include "monty.h"

/**
 * freeStack - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */

void freeStack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}

/**
 * freeList - frees getline list
 * @a: pointer to array of strings
 * Return: Nothing
 */

void freeList(char *a[])
{
	int i = 0;

	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
}
