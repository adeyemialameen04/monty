#include "main.h"

/**
 * _print - Custom write function to print a string or char.
 * @printval: Value to be printed.
 * @fd: File descriptor its printing to.
 * Return: None.
 */
void _print(int fd, char *printval)
{
	write(fd, printval, strlen(printval));
}

/**
 * _print_number - Print an integer to the specified file descriptor.
 * @fd: The file descriptor to print to.
 * @num: The integer to print.
 */
void _print_number(int fd, int num)
{
	char buffer[20];
	int length = snprintf(buffer, sizeof(buffer), "%d", num);

	write(fd, buffer, length);
}
