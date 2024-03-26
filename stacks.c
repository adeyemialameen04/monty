#include "main.h"

void (*get_op_function(char *str))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{NULL, NULL}};

	while (instructions[i].opcode != NULL)
	{
		if (str != NULL && _strcmp(instructions[i].opcode, str) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}

	return (NULL);
}

void push(stack_t **stack, unsigned int line_number)
{
	if (data->argc != 2)
	{
	}

	printf("Push %d\n", line_number);
}

void pop(stack_t **stack, unsigned int line_number)
{
	printf("Pop %d\n", line_number);
}

void pall(stack_t **stack, unsigned int line_number)
{
	printf("Pall %d\n", line_number);
}
