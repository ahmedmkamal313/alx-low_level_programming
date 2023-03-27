#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: string to get length of.
 * Return: the length of @s.
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;

	return (length);
}
