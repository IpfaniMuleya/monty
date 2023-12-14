#include "monty.h"

/**
 * free_pop - Removes the top element of the stack.
 * @head: Pointer to the head of the stack.
 */
void free_pop(stack_t **head)
{
	stack_t *temp = *head;

	if (*head == NULL)
		return;

	*head = (*head)->next;
	free(temp);
}
