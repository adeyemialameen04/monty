#include "monty.h"

void trim_whitespace(char *str);

FILE *glob_fd_ptr = NULL;

void read_file(char *argv[], data_t *data);
/**
 * read_file -read and execute opcodes.
 * @argv: array of strings.
 * @data: My data struct.
 * Return: None.
 */
void read_file(char *argv[], data_t *data)
{
	ssize_t read;
	size_t n = 0;
	FILE *fd = fopen(argv[1], "r");

	glob_fd_ptr = fd;

	data->line_num = 0;

	if (fd == NULL)
	{
		print_errmsg_cant_open_file(argv[1]);
		exit(EXIT_FAILURE);
	}

	_free_argv(data);
	while ((read = custom_getline(&data->cmd, &n, fd)) != -1)
	{
		void (*op_fn)(stack_t **stack, unsigned int line_number);

		(data->line_num)++;

		if (read <= 1 || (read == 2 && data->cmd[0] == ' ' && data->cmd[1] == '\n'))
		{
			if (data->cmd != NULL)
			{
				free(data->cmd);
				data->cmd = NULL;
			}
			continue;
		}

		trim_whitespace(data->cmd);

		if (strlen(data->cmd) == 0)
		{
			continue;
		}

		_tokenize_line(data, " \n");

		if (data->argv != NULL)
		{
			char *opcode = NULL;

			opcode = data->argv[0];

			if (opcode == NULL)
			{
				if (data->cmd != NULL)
				{
					free(data->cmd);
					data->cmd = NULL;
				}
				continue;
			}

			op_fn = get_op_function(opcode);

			if (op_fn != NULL)
			{
				op_fn(data->stack, data->line_num);
				_free_argv(data);
			}
			else
			{
				char line_num_str[20];

				itoa(data->line_num, line_num_str);
				print_errmsg_invalid_opcode(line_num_str, data);
				if (data->cmd != NULL)
				{
					free(data->cmd);
					data->cmd = NULL;
				}
				_free_argv(data);
				fclose(fd);
				exit(EXIT_FAILURE);
			}

			_free_argv(data);
		}
	}

	if (data->cmd != NULL)
	{
		free(data->cmd);
		data->cmd = NULL;
	}

	fclose(fd);
}
