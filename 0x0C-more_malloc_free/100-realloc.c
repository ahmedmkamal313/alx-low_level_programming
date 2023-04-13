#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocate a memory block using malloc and free.
 * @ptr: a pointer to memory.
 * @old_size: the size of allocated space for ptr.
 * @new_size: the new size of the new memory block.
 * Return: a pointer to the new space in memory,
 * ptr if new_size == old_size, call free and return NULL if
 * new size == 0, NULL if fails.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		else
			return (new_ptr);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		for (i = 0; i < old_size && i < old_size; i++)
			*((char *)new_ptr + i) = *((char *)ptr + i);
	else
		for (i = 0; i < old_size && i < new_size; i++)
			*((char *)new_ptr + i) = *((char *)ptr + i);

	free(ptr);

	return (new_ptr);
}
