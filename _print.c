#include "monty.h"

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
