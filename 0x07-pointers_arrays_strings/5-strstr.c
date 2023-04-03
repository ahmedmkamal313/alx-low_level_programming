#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring.
 * @haystack: the string to be searched.
 * @needle: the substring to be located.
 * Return: hystack if found, NULL if not found.
 */

char *_strstr(char *haystack, char *needle)
{
	int i, hs = 0;

	while (needle[s] != '\0')
		hs++;

	while (*hystack)
	{
		for (i = 0 ; needle[i] ; i++)
		{
			if (haystack[i] != needle[i])
				break;
		}
		if (i != s)
			haystack++;
		else
			return (haystack);
	}

	return (NULL);
}
