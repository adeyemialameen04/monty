
#include "monty.h"
#define MAX_DIGITS 12

/**
 * _strlen - Calculate the length of a string
 * @s: Pointer to the string
 *
 * Description: This function takes as an argument a pointer to a string (s)
 * and calculates the length of the string by iterating through its characters
 * until it encounters the null terminator ('\0').
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int count = 0, i = 0;

	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > (INT_MAX - (s[i] - '0')) / 10)
		{
			return ((sign == 1) ? INT_MAX : INT_MIN);
		}
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (sign * result);
}

/**
 * _strdup - Duplicates a string in newly allocated memory.
 * @str: The input string to duplicate.
 *
 * Return: A pointer to the newly allocated string (duplicate).
 *         NULL if str is NULL or if memory allocation fails.
 */

char *_strdup(char *str)
{
	unsigned int i, length = 0;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

/**
 * itoa - convert number to string.
 * @num: Number to be converted.
 * @str: String its going to save it to.
 * Return: The string.
 */
char *itoa(int num, char *str)
{
	char temp[MAX_DIGITS];
	int i = 0, j = 0;

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}

	while (num != 0)
	{
		temp[i++] = '0' + num % 10;
		num /= 10;
	}

	while (i > 0)
	{
		str[j++] = temp[--i];
	}

	str[j] = '\0';

	return (str);
}

/**
 * trim_whitespace - Trim all whitespaces in a str.
 * @str: The string to be trimmed.
 * Return: None
 */
void trim_whitespace(char *str)
{
	char *start = str;
	char *end = str + strlen(str) - 1;

	while (isspace((unsigned char)*start))
		start++;

	if (*start == '\0')
	{
		*str = '\0';
		return;
	}

	while (end >= start && isspace((unsigned char)*end))
		end--;

	*(end + 1) = '\0';

	if (start != str)
		memmove(str, start, end - start + 2);
}
