#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1: the first string.
 * @s2: the second string to be compared.
 * Return: result.
 */

int _strcmp(char *s1, char *s2)
{
	int result = 0;

	while (*s1 && *s2 && (result == 0))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		{
			result = (*s1 < *s2) ? -15 : 15;
		}
	}
	if (result == 0)
	{
		result = (*s1 < *s2) ? -1 : (*s1 > *s2) ? 15 : 0;
	}

	return (result);
}
