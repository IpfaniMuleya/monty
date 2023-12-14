#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	unsigned int i;
	instruction_t opst[] = {
		{"push", push}, {"pall", pall},
		{NULL, NULL}
	};

	char *op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	monty_state.arg = strtok(NULL, " \n\t");

	for (i = 0; opst[i].opcode; i++)
	{
		if (op && strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
	}

	if (op)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
