#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
monty_state_t monty_state = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read_line = getline(&content, &size, file)) > 0)
	{
		counter++;

		if (content[read_line - 1] == '\n')
			content[read_line - 1] = '\0';

		execute(content, &stack, counter, file);
	}

	free(content);
	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
