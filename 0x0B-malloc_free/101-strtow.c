#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * strtow - splits a string into words.
 * @str: string to split.
 * Return: pointer to array of strings, NULL if failed.
 */

char **strtow(char *str)
{
	int i = 0, j = 0, k = 0;
	size_t len;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	len = strlen(str);
	words = malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
		{
			i++;
		}
		j = i;
		while (str[j] != ' ' && str[j] != '\0')
		{
			j++;
		}
		words[k] = malloc(sizeof(char) * (j - i + 1));
		if (words[k] == NULL)
		{
			for (i = 0; i < k; i++)
			{
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		strncpy(words[k], &str[i], j - i);
		words[k][j - i] = '\0';
		k++;
		i = j;
	}
	words[k] = NULL;
	return (words);
}
