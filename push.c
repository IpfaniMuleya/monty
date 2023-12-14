#include "monty.h"

/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void push(stack_t **head, unsigned int counter)
{
	char *arg = monty_state.arg;

	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(monty_state.file);
		free(monty_state.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	while (*arg)
	{
		if (!isdigit(*arg) && !(*arg == '-' && isdigit(*(arg + 1))))
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(monty_state.file);
			free(monty_state.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		arg++;
	}

	addnode(head, atoi(monty_state.arg));
}
