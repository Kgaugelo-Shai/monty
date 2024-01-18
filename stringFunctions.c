#include "monty.h"

/**
 * pcharf - prints the char at the top of the stack, then new line
 * @head: stack head
 * @line_num: line_number
 * Return: void
*/
void pcharf(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
