#include "monty.h"

/**
 * swap - Swap the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}

