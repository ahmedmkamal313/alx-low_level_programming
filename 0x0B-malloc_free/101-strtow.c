#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_space - helper function to check if a character is a space.
 * @c: space
 * Return: c.
 */

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * count_words - helper function to count the number
 * of words in a string.
 * @str: string.
 * Return: count.
 */

int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		if (!is_space(str[i]))
		{
			count++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}

/**
 * strtow - splits a string into words.
 * @str: string to split.
 * Return: pointer to array of strings, NULL if failed.
 */

char **strtow(char *str)
{
	char **words;
	int i = 0, j = 0, k = 0, l;
	int word_count = count_words(str);

	if (!str || !*str || !word_count)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);

	while (str[i])
	{
		if (!is_space(str[i]))
		{
			j = i;
			while (str[j] && !is_space(str[j]))
				j++;

			words[k] = malloc(sizeof(char) * (j - i + 1));
			if (!words[k])
				return (NULL);

			for (l = 0; l < j - i; l++)
				words[k][l] = str[i + l];
			words[k][j - i] = '\0';

			k++;
			i = j;
		}
		else
		{
			i++;
		}
	}

	words[k] = NULL;

	return (words);
}
