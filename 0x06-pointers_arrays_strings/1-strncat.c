#include "main.h"

/**
 * _strncat - concatenates two strings.
 * @dest: destination.
 * @src: source
 * @n: int
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}
