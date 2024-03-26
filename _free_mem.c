#include "main.h"

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
			free(data->argv[i]);
			data->argv[i] = NULL;
		}
		free(data->argv);
		data->argv = NULL;
	}
}
