#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value
 * is located, or NULL if not found or list is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *curr;

	if (list == NULL)
		return (NULL);

	prev = list;
	curr = list->express;

	while (curr != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n >= value)
			break;
		prev = curr;
		curr = curr->express;
	}

	if (curr == NULL)
	{
		curr = prev;
		while (curr->next != NULL)
			curr = curr->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, curr->index);

	while (prev != NULL && prev->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
