#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers using the
 * Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value
 * is located, or NULL if not found or list is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *prev, *curr;
	size_t step, i;

	if (list == NULL || size == 0)
		return (NULL);

	step = sqrt(size);
	prev = list;
	curr = list;
	i = 0;

	while (curr->next != NULL && curr->n < value)
	{
		prev = curr;
		i += step;
		while (curr->next != NULL && curr->index < i)
			curr = curr->next;
	printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
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
