#include "monty.h"

/**
 * pall - prints the stack
 * @head: stack head
 * @counter: unused
 * Return: void
 */
void pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;
	
	current = *head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
