#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate.
 * Return: On success, a pointer to the duplicated string. It returns NULL
 * if insufficient memory was available or if str is NULL.
 */

char *_strdup(char *str)
{
	char *dup_str;
	size_t len;
	int i;

	if (str == NULL)
		return (NULL);

	len = strlen(str) + 1;

	dup_str = malloc(len * sizeof(char));

	if (dup_str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		dup_str[i] = str[i];
	dup_str[i] = '\0';

	return (dup_str);
}
