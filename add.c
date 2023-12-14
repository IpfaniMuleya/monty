#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void _add(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(monty_state.file);
		free(monty_state.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
	pop(head, counter);
}
