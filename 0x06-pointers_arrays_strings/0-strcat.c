#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: destination.
 * @src: the source.
 * Return: dest.
 */

char *_strcat(char *dest, char *src)
{
	size_t src_len = strlen(src);
	size_t dest_len = strlen(dest);

	for (int i = 0; i <= src_len; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + src_len] = '\0';
	return (dest);
}
