#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @h: pointer to the head of the list.
 * Return: the number of elements.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0; /* initialize a counter variable */

	while (h != NULL) /* loop through the list until the end */
	{
		count++; /* increment the counter */
		h = h->next; /* move to the next node */
	}

	return (count);
}
