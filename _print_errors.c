#include "monty.h"

void print_errmsg_invalid_opcode(char *str, data_t *data)
{
	_print(STDERR_FILENO, "L");
	_print(STDERR_FILENO, str);
	_print(STDERR_FILENO, ": unknown instruction ");
	_print(STDERR_FILENO, data->argv[0]);
	_print(STDERR_FILENO, "\n");
}

void print_errmsg_cant_open_file(char *filename)
{
	_print(STDERR_FILENO, "Error: Can't open file ");
	_print(STDERR_FILENO, filename);
	_print(STDERR_FILENO, "\n");
}

void _print_errmsg_cant_do_op(char *str, char *err_cant)
{
	_print(STDERR_FILENO, "L");
	_print(STDERR_FILENO, str);
	_print(STDERR_FILENO, err_cant);
}
