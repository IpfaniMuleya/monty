#include "monty.h"

/**
 * _sub - Subtraction.
 * @head: Stack head.
 * @counter: Line number.
 * Return: No return.
 */
void _sub(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(monty_state.file);
		free(monty_state.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n -= (*head)->n;
}
