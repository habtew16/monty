#include "monty.h"

/**
 * pall - print the stack
 * @head: double pointer to head of d linked list
 * @line_count: current line of monty file
 * Return: returns void
 */
void pall(stack_t **head, __attribute__((unused)) unsigned int line_count)
{
	stack_t *temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

