#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list.
 * @index: the index of the node, starting from 0
 * Return: the nth node, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0; /* declare a counter variable */

	while (head != NULL) /* loop through the list until the end */
	{
		if (i == index) /* check if the counter matches the index */
			return (head); /* return the current node */
		i++; /* increment the counter */
		head = head->next; /* move to the next nods */
	}
	return (NULL);
}
