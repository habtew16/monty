#include "monty.h"

/**
* push - Push an element onto the stack.
* @node: Pointer to the head of the stack.
* @line_count: Current line number.
*
* Return: void
*/
void push(stack_t **node, unsigned int line_count)
{
	stack_t *new;
	char *param;
	int num;

	param = strtok(NULL, SEPARATORS);

	if (!param)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		_free(*node);
		exit(EXIT_FAILURE);
	}
	num = atoi(param);

	if (num == 0 && strcmp(param, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		_free(*node);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free(*node);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	new->next = NULL;

	if (*node == NULL)
		*node = new;
	else
	{
		new->next = *node;
		(*node)->prev = new;
		*node = new;
	}
}

