#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - search for a integer.
 * @array: the array.
 * @size: the size of the array.
 * @cmp: pointer to the function to be used to compare values.
 * Return: the index of the 1st element for which the cmp fun
 * doesnt return 0. if no elements matches, return -1.
 * if size <+0 return -1.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
		return (-1);

	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}
