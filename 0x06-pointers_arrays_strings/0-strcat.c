#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: destination.
 * @src: the source.
 * Return: dest.
 */

char *_strcat(char *dest, char *src)
{
	int i, destLen = 0;

	while (dest[destLen])
		destLen++;

	for (i = 0 ; src[i] != 0 ; i++)
	{
		dest[destLen] = src[i];
		destLen++;
	}

	dest[destLen] = '\0';
	return (dest);
}
