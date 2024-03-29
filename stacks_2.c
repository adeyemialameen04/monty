#include "monty.h"

/**
 * is_empty - To check if the stack is empty.
 * @stack: Double pointer to the stack.
 * Return: True/False.
 */
bool is_empty(stack_t **stack)
{
	return (*stack == NULL);
}

/**
 * stack_list - Counts the number of elements in a stack.
 * @stack: Double pointer to the stack.
 * Return: No of elements.
 */
int stack_list(stack_t **stack)
{
	int i = 0;
	stack_t *curr = *stack;

	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}

	return (i);
}

/**
 * swap - Swap the first two elements in the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	char str[20];
	int number_one, number_two;

	itoa(line_number, str);

	if (stack_list(stack) < 2)
	{
		_print_errmsg_cant_do_op(str, ": can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}

	number_one = (*stack)->n;
	number_two = (*stack)->next->n;

	(*stack)->n = number_two;
	(*stack)->next->n = number_one;
}

/**
 * nop - Nop does nothing.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
