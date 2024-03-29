#include "monty.h"
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>

/**
 * get_op_function - get opcode function.
 * @str: String to compare with.
 * Return: None.
 */
void (*get_op_function(char *str))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"#", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	while (instructions[i].opcode != NULL)
	{
		if (str != NULL && strcmp(instructions[i].opcode, str) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}

	if (str != NULL && strchr(str, '#') != NULL)
	{
		return (nop);
	}

	return (NULL);
}

/**
 * push - Push element onto the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void push(stack_t **stack, unsigned int line_number)
{
	data_t *data_ptr = glob_data_ptr;
	FILE *fd_ptr = glob_fd_ptr;
	char str[20];
	char *end_ptr;
	int value;
	stack_t *new_node = NULL;

	itoa(line_number, str);

	if (data_ptr->argc < 2)
	{
		_print_errmsg_cant_do_op(str, ": usage: push integer\n");
		cleanup(data_ptr, true);
		if (fd_ptr != NULL)
			fclose(fd_ptr);
		exit(EXIT_FAILURE);
	}

	value = strtol(data_ptr->argv[1], &end_ptr, 10);
	if (end_ptr == data_ptr->argv[1] || *end_ptr != '\0')
	{
		_print_errmsg_cant_do_op(str, ": usage: push integer\n");
		cleanup(data_ptr, true);
		if (fd_ptr != NULL)
			fclose(fd_ptr);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		_print(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pop - Pop element out of the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	char str[20];
	stack_t *temp = NULL;

	itoa(line_number, str);

	if (is_empty(stack))
	{
		_print_errmsg_cant_do_op(str, ": can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = temp->next;

	free(temp);
}

/**
 * pall - prints all the elements in a stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint - print the value of the first element in the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	char str[20];
	int top_value;

	itoa(line_number, str);

	if (is_empty(stack))
	{
		_print_errmsg_cant_do_op(str, ": can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}

	top_value = (*stack)->n;

	printf("%d\n", top_value);
}
