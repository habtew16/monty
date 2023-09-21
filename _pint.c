#include "monty.h"

/**
 * m_pint - Print the value at the top of the stack.
 * @node: Pointer to the head of the stack.
 * @line_count: Current line number.
 *
 * Return: void
 */
void pint(stack_t **node, unsigned int line_count)
{
	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_count);
		_free(*node);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node)->n);
}

