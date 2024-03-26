#include "main.h"

void read_file(char *argv[], data_t *data)
{
	ssize_t read;
	size_t n = 0;
	FILE *fd = fopen(argv[1], "r");
	data->line_num = 0;

	if (fd == NULL)
	{
		_print(STDERR_FILENO, "Error: Can't open file ");
		_print(STDERR_FILENO, argv[1]);
		_print(STDERR_FILENO, "\n");
		exit(EXIT_FAILURE);
	}

	while ((read = custom_getline(&data->cmd, &n, fd)) != -1)
	{
		void (*op_fn)(stack_t **stack, unsigned int line_number);

		if (read == 0 || (read == 1 && data->cmd[0] == '\n'))
			continue;

		(data->line_num)++;
		_tokenize_line(data, " \n");

		if (data->argv[0] == NULL)
			return;

		op_fn = get_op_function(data->argv[0]);

		if (op_fn != NULL)
		{
			op_fn(data->stack, data->line_num);
		}
		_free_argv(data);
	}

	free(data->cmd);
	data->cmd = NULL;

	fclose(fd);
}
