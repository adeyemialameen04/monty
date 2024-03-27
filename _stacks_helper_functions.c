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
