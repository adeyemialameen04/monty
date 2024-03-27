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

	if (ascii_val >= 0 && ascii_val <= 127)
	{
		putchar(ascii_val);
		putchar('\n');
	}
	else
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't pchar, value out of range\n");
		exit(EXIT_FAILURE);
	}
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
