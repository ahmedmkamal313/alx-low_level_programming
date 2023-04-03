#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: segment for bytes
 * @accept: bytes to include or accept.
 * Return: k
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, k = 0;

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		if (s[i] != 32)
		{
			for (j = 0 ; accept[j] != '\0' ; j++)
			{
				if (s[i] == accept[j])
					k++;
			}
		}
		else
			return (k);
	}

	return (k);
}
