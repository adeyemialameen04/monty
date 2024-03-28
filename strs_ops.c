#include "monty.h"

/**
 * pchar - Prints the ascii representation of the topmost value.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	data_t *data_ptr = glob_data_ptr;
	FILE *fd_ptr = glob_fd_ptr;
	int ascii_val;
	char str[20];

	itoa(line_number, str);

	if (stack == NULL || is_empty(stack))
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't pchar, stack empty\n");
		_free_argv(data_ptr);
		free(data_ptr->cmd);
		data_ptr->cmd = NULL;
		if (fd_ptr != NULL)
			fclose(fd_ptr);
		exit(EXIT_FAILURE);
	}

	ascii_val = (*stack)->n;

	if (!__isascii(ascii_val))
	{
		_print(STDERR_FILENO, "L");
		_print(STDERR_FILENO, str);
		_print(STDERR_FILENO, ": can't pchar, value out of range\n");
		_free_argv(data_ptr);
		free(data_ptr->cmd);
		data_ptr->cmd = NULL;
		_free_stack(stack);
		if (fd_ptr != NULL)
			fclose(fd_ptr);
		exit(EXIT_FAILURE);
	}
	putchar(ascii_val);
	putchar('\n');
}

#define STACK_EMPTY_ERROR "L%u: can't pstr, stack empty\n"
#define VALUE_OUT_OF_RANGE_ERROR "L%u: can't pstr, value out of range\n"
/**
 * pstr - Prints the ascii representation of the stack as a string.
 * @stack: double pointer to the stack.
 * @line_number: Line number.
 * Return: none.
 */
void pstr(stack_t **stack, unsigned int line_number)
{

	stack_t *curr = NULL;

	(void)line_number;

	if (stack == NULL || is_empty(stack))
	{

		fprintf(stderr, STACK_EMPTY_ERROR, line_number);
		return;
	}

	curr = *stack;

	while (curr != NULL && curr->n != 0)
	{
		if (curr->n > 0 && curr->n <= 127)
		{
			putchar(curr->n);
		}
		else
		{
			break;
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
