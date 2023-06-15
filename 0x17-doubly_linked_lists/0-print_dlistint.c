#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the head of the list
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0; /* initialize a counter variable */

	while (h != NULL) /* loop through the list until the end */
	{
		printf("%d\n", h->n); /* print the data of the current node */
		count++; /* increment the counter */
		h = h->next; /* move to the next node */
	}
	return (count);
}
