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
		_print(STDERR_FILENO, "Error: Can't open file ");
		_print(STDERR_FILENO, argv[1]);
		_print(STDERR_FILENO, "\n");
		exit(EXIT_FAILURE);
	}

	while ((read = custom_getline(&data->cmd, &n, fd)) != -1)
	{
		void (*op_fn)(stack_t **stack, unsigned int line_number);
		/* int isEmpty = 1;*/

		if (read <= 1 || (read == 2 && data->cmd[0] == ' ' && data->cmd[1] == '\n'))
			continue;

		trim_whitespace(data->cmd);

		(data->line_num)++;

		_tokenize_line(data, " \n");

		op_fn = get_op_function(data->argv[0]);

		if (op_fn != NULL)
		{
			op_fn(data->stack, data->line_num);
		}
		else
		{
			char str[20];

			itoa(data->line_num, str);
			_print(STDERR_FILENO, "L");
			_print(STDERR_FILENO, str);
			_print(STDERR_FILENO, ": unknown instruction ");
			_print(STDERR_FILENO, data->argv[0]);
			_print(STDERR_FILENO, "\n");
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

	if (data->cmd != NULL)
	{
		free(data->cmd);
		data->cmd = NULL;
	}

	fclose(fd);
}

/**
 * trim_whitespace - Trim all whitespaces in a str.
 * @str: The string to be trimmed.
 * Return: None
 */
void trim_whitespace(char *str)
{
	char *dest;

	while (*str != '\0' && isspace(*str))
	{
		str++;
	}

	dest = str;
	while (*str != '\0')
	{
		*dest++ = *str++;
	}
	*dest = '\0';
}
