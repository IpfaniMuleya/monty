#include "monty.h"

/**
 * pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint(stack_t **head, unsigned int counter)
{
	stack_t *top;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}

	top = *head;
	printf("%d\n", top->n);
}
