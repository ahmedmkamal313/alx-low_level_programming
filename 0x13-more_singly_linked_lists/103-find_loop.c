#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to pointer to the head of the list.
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current, *last;

	if (head == NULL)
		return (NULL);

	for (last = head->next; last != NULL; last = last->next)
	{
		if (last == last->next)
			return (last);

		for (current = head; current != last; current = current->next)
			if (current == last->next)
				return (last->next);
	}

	return (NULL);
}
