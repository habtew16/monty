#include "monty.h"

/**
* _execute - Search for Monty instructions and execute them.
* @instruction: The Monty instruction to search.
* @stack: Pointer to the head of the stack.
* @line_number: Current line number in the Monty file.
*/



void _execute(char *instruction, stack_t **stack, unsigned int line_number)
{
	size_t index = 0;
	int instruction_found = 0;

	instruction_t valid_instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
	};

	while (valid_instructions[index].opcode != NULL)
	{
		if (strcmp(valid_instructions[index].opcode, instruction) == 0)
		{
			instruction_found = 1;
			break;
		}
		index++;
	}

	if (instruction_found)
		valid_instructions[index].f(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
}

