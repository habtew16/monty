#include "monty.h"

/**
 * free_all - Frees all memory allocated for the stack.
 * @stack: Pointer to the head of the stack.
 */

void _free(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

