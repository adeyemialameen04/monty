#include "monty.h"

/**
 * print_errmsg_invalid_opcode - Prints an error message for an unknown opcode.
 * @str: The line number where the error occurred as a string.
 * @data: Pointer to the data structure containing command information.
 *
 * Description: Prints an error message indicating that an unknown instruction
 * was encountered at the specified line number during opcode execution.
 */
void print_errmsg_invalid_opcode(char *str, data_t *data)
{
	_print(STDERR_FILENO, "L");
	_print(STDERR_FILENO, str);
	_print(STDERR_FILENO, ": unknown instruction ");
	_print(STDERR_FILENO, data->argv[0]);
	_print(STDERR_FILENO, "\n");
}

/**
 * print_errmsg_cant_open_file - Prints an error message for a
 * failed file open operation.
 * @filename: The name of the file that could not be opened.
 * Description: Prints an error message indicating that the
 * specified file could not be opened.
 */
void print_errmsg_cant_open_file(char *filename)
{
	_print(STDERR_FILENO, "Error: Can't open file ");
	_print(STDERR_FILENO, filename);
	_print(STDERR_FILENO, "\n");
}

/**
 * _print_errmsg_cant_do_op - Prints an error message for an
 * operation that cannot be performed.
 * @str: The line number or other identifier for the operation as a string.
 * @err_cant: The reason why the operation cannot be performed.
 *
 * Description: Prints an error message indicating that an operation
 * cannot be performed
 * at the specified line number or under the specified condition.
 */
void _print_errmsg_cant_do_op(char *str, char *err_cant)
{
	_print(STDERR_FILENO, "L");
	_print(STDERR_FILENO, str);
	_print(STDERR_FILENO, err_cant);
}
