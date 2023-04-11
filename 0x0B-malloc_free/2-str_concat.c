#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two strings.
 * @s1: the first string to concatenate.
 * @s2: the second string to concatenate.
 * Return: on success a pointer to the c string,
 * null if fail.
 */

char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int i, j;
	size_t len1, len2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	concat_str = malloc((len1 + len2 + 1) * sizeof(char));
	if (concat_str == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		concat_str[i] = s1[i];
	for (j = 0; s2[j] != '\0'; j++)
		concat_str[i + j] = s2[j];

	concat_str[i + j] = '\0';
	return (concat_str);
}
