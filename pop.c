#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	free(temp);
}
