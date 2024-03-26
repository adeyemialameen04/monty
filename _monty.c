#include "main.h"

int _monty(int argc, char *argv[])
{
	data_t data = initialize_data_struct();

	if (argc == 1)
	{
		_print(STDERR_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	read_file(argv, &data);

	return (data.exit_status);
}
