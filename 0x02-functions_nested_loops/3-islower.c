#include "main.h"

/**
 * _islower - checks for lowercase character.
 * @c: the character to checked.
 * Return: 1 if c is lowercase, 0 otherwise.
 */

int _islower(int c)
{
	int r;

	if (r >= 'a' && r <= 'z')
		return (1);
	else
		return (0);
}
