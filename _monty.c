#include "monty.h"

int _monty(int argc, char *argv[]);
data_t *glob_data_ptr = NULL;

/**
 * _monty - Baba func.
 * @argc: Args count.
 * @argv: Array of strings.
 * Return:  exit status.
 */
int _monty(int argc, char *argv[])
{
	data_t data = initialize_data_struct();
	stack_t *stack = NULL;

	data.stack = &stack;
	glob_data_ptr = &data;

	if (argc == 1)
	{
		_print(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1] != NULL && argv[2] != NULL)
	{
		if (strcmp(argv[1], argv[2]) == 0)
		{
			_print(STDERR_FILENO, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}
	}

	read_file(argv, &data);
	_free_stack(&stack);

	return (data.exit_status);
}
