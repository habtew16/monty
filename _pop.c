#include "monty.h"

/**
* pop - Remove the top element from the stack.
* @node: Pointer to the head of the stack.
* @line_count: Current line number.
*
* Return: void
*/

void pop(stack_t **node, unsigned int line_count)
{
	stack_t *top;
	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		_free(*node);
		exit(EXIT_FAILURE);
	}

	top = *node;
	*node = top->next;

	if (*node != NULL)
	{
		(*node)->prev = NULL;
	}

	free(top);
}

