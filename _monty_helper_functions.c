#include "monty.h"
#include <limits.h>

/**
 * initialize_data_struct - Initialize data struct.
 * Return: the data_t struct.
 */
data_t initialize_data_struct(void)
{
	data_t data;

	data.cmd = NULL;
	data.argv = NULL;
	data.exit_status = 0;
	data.stack = NULL;
	data.argc = 0;
	data.line_num = 0;

	return (data);
}
