#include "monty.h"

/**
 * pchar - Prints the ascii representation of the topmost value.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_val;
	char str[20];

	itoa(line_number, str);

	if (is_empty(stack))
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't pchar, stack empty\n");
		exit(EXIT_FAILURE);
	}

	ascii_val = (*stack)->n;

	if (ascii_val > 127 || ascii_val < 0)
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't pchar, value out of range\n");
		exit(EXIT_FAILURE);
	}
	putchar(ascii_val);
	putchar('\n');
}

/**
 * pstr - Prints the ascii representation of the stack as a string.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = NULL;
	char str[20];

	itoa(line_number, str);

	if (is_empty(stack))
	{
		putchar('\n');
	}

	curr = *stack;

	while (curr != NULL && curr->n != 0)
	{
		if (curr->n >= 0 && curr->n <= 127)
		{
			putchar(curr->n);
		}

		curr = curr->next;
	}

	putchar('\n');
}

/**
 * rotl - rotate left, makes the top become the end and the second
 *				top become the top.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *top = *stack, *sec_top = (*stack)->next;

		while (top->next != NULL)
			top = top->next;

		top->next = *stack;
		(*stack)->next = NULL;
		*stack = sec_top;
	}
}

/**
 * rotr - rotate right, makes the top become the bottom.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if (is_empty(stack) || (*stack)->next == NULL)
		return;

	curr = *stack;

	(void)line_number;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->prev->next = NULL;
	curr->next = *stack;
	curr->prev = NULL;
	(*stack)->prev = curr;
	*stack = curr;
}
