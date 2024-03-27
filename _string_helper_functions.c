
#include "main.h"
#define MAX_DIGITS 12 /* Maximum number of digits for a 32-bit integer (including sign) */

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
 * _strcmp - Compares two strings lexicographically.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: An integer less than, equal to, or greater than 0 if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
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
 * _strchr - Locates a character in a string.
 *
 * @s: A pointer to the string to be searched.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of the
 * character @c in the string @s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}

	return (NULL);
}

char *itoa(int num, char *str)
{
	char temp[MAX_DIGITS]; /* Temporary buffer to store the digits */
	int i = 0, j = 0;

	/* Handle the case of 0 separately */
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return str;
	}

	/* Handle negative numbers */
	if (num < 0)
	{
		str[i++] = '-';
		num = -num; /* Make the number positive for simplicity */
	}

	/* Extract digits from right to left */
	while (num != 0)
	{
		temp[i++] = '0' + num % 10;
		num /= 10;
	}

	/* Reverse the digits in temp and copy to str */
	while (i > 0)
	{
		str[j++] = temp[--i];
	}

	str[j] = '\0'; /* Null-terminate the string */

	return str;
}
