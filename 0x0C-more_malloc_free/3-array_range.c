#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - creates an array of int.
 * @min: the min value of array.
 * @max: the max value of the array.
 * Return: a pointer to created array, NULL if min > max or fail.
 */

int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(sizeof(int) * size);

	if (arr == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		arr[i] = min++;

	return (arr);
}
