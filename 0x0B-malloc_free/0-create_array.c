#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - creates array of chars, initializes it with a specific char.
 * @size: size
 * @c: the
 * Return: a pointer to the array, or NULL if it fails.
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr = malloc(size * sizeof(char));

	if (size == 0 || arr == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		arr[i] = c;
	return (arr);
}
