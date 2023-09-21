#include "monty.h"

/**
 * add - Add the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

