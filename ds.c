#include "monty.h"

/**
 * ds_queue - To change the list to a queue.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line number of the file.
 * Return: None.
 */
void ds_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	list_type = 1;
}

/**
 * ds_stack - To change the list to a queue.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line number of the file.
 * Return: None.
 */
void ds_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	list_type = 0;
}
