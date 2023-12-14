#include "monty.h"

/**
 * _div - Divides the second top element of the stack by the top element.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void _div(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(monty_state.file);
		free(monty_state.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(monty_state.file);
		free(monty_state.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	free_pop(head);
}
