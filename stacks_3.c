#include "monty.h"

/**
 * sub - Subtracts the first two elements in the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	char str[20];
	int number_one, number_two, res;

	itoa(line_number, str);

	if (stack_list(stack) < 2)
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't sub, stack too short\n");
		exit(EXIT_FAILURE);
	}

	number_one = (*stack)->n;
	number_two = (*stack)->next->n;

	res = number_two - number_one;

	pop(stack, line_number);

	(*stack)->n = res;
}

/**
 * divide - Divides the first two elements in the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	char str[20];
	int number_one, number_two, res;

	itoa(line_number, str);

	if (stack_list(stack) < 2)
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't div, stack too short\n");
		exit(EXIT_FAILURE);
	}

	number_one = (*stack)->n;

	if (number_one == 0)
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": division by zero\n");
		exit(EXIT_FAILURE);
	}

	number_two = (*stack)->next->n;

	res = number_two / number_one;

	pop(stack, line_number);

	(*stack)->n = res;
}

/**
 * mul - Multiplies the first two elements in the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	char str[20];
	int number_one, number_two, res;

	itoa(line_number, str);

	if (stack_list(stack) < 2)
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't mul, stack too short\n");
		exit(EXIT_FAILURE);
	}

	number_one = (*stack)->n;
	number_two = (*stack)->next->n;

	res = number_two * number_one;

	pop(stack, line_number);

	(*stack)->n = res;
}

/**
 * mod - Finds the modulo the first two elements in the stack.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	char str[20];
	int number_one, number_two, res;

	itoa(line_number, str);

	if (stack_list(stack) < 2)
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't sub, stack too short\n");
		exit(EXIT_FAILURE);
	}

	number_one = (*stack)->n;

	if (number_one == 0)
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": division by zero\n");
		exit(EXIT_FAILURE);
	}

	number_two = (*stack)->next->n;

	res = number_two % number_one;

	pop(stack, line_number);

	(*stack)->n = res;
}
