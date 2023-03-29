#include "main.h"

/**
 * leet - encodes string to 1337.
 * @s: string to be encoded.
 * Return: r.
 */

char *leet(char *s)
{
	char *r = s;
	char a[] = { 'a', 'e', 'o', 't', 'l' };
	char n[] = { 4, 3, 0, 7, 1 };
	int i = 0;

	while (*s)
	{
		for (i = 0; i < 5; i++)
		{
			if (*s == a[i] || *s == a[i] - 32)
				*s = n[i] + '0';
		}
		s++;
	}

	return (r);
}
