#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * main - entry function or monty program
 * @argc: the numberof arguments passed
 * @argv: list of the arguments
 * Return: always return 0
*/

int main(int argc, char *argv[])
{
	char *instruction;
	FILE *montyFile;
	char *lineBuffer = NULL;
	size_t bufferSize = 0;
	unsigned int lineNumber = 0;

	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	montyFile = fopen(argv[1], "r");
	if (!montyFile)
	{
		fprintf(stderr, "USAGE: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&lineBuffer, &bufferSize, montyFile) != -1)
	{
		lineNumber++;
		instruction = strtok(lineBuffer, SEPARATORS);

		if (instruction && instruction[0] != '#')
		{
			_execute(instruction, &stack, lineNumber);
		}
	}

	fclose(montyFile);
	free(lineBuffer);
	_free(stack);

	return (EXIT_SUCCESS);
}

