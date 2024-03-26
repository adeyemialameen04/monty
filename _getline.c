#include "main.h"

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int ch;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128; /* Initial buffer size */
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1); /* Error allocating memory */
		}
	}

	while ((ch = fgetc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			size_t new_size = *n * 2;
			char *new_ptr = realloc(*lineptr, new_size);

			if (new_ptr == NULL)
			{
				return (-1); /* Error reallocating memory */
			}
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[pos++] = ch;
		if (ch == '\n')
		{
			break;
		}
	}

	if (pos == 0 || ferror(stream))
	{
		return (-1); /* Error reading from stream */
	}

	(*lineptr)[pos] = '\0'; /* Null-terminate the string */

	return (pos); /* Return the number of characters read */
}
