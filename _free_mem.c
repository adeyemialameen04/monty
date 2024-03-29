#include "monty.h"

/**
 * _free_argv - Free the elements inside argv and set to NULL.
 * @data: The data struct.
 * Return: none.
 */
void _free_argv(data_t *data)
{
	int i;

	if (data->argv != NULL)
	{
		for (i = 0; data->argv[i] != NULL; i++)
		{
			if (data->argv[i] != NULL)
			{
				free(data->argv[i]);
				data->argv[i] = NULL;
			}
		}
		free(data->argv);
		data->argv = NULL;
	}
}

/**
 * _free_stack - Frees the elements in a stack.
 * @stack: The stack.
 * Return: None.
 */
void _free_stack(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *next;

	if (*stack == NULL)
	{
		return;
	}

	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}

	*stack = NULL;
}

/**
 * cleanup - Clean dynamically allocated mem.
 * @data: Data struct.
 * @fs: free stack or not.
 * Return: None.
 */
void cleanup(data_t *data, bool fs)
{
	_free_argv(data);

	if (data->cmd != NULL)
	{
		free(data->cmd);
		data->cmd = NULL;
	}

	if (fs == true)
		_free_stack(data->stack);
}
