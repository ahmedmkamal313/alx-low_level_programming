#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: double pointer to the head of the list.
 * @idx: the index of the list where the new node should be added.
 * @n: the data of the new node.
 * Return: the address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	/* declare a new and temprary node pointer */
	dlistint_t *new, *tmp;
	unsigned int i = 0; /* declare a counter variable */

	if (h == NULL) /* return NULL if the list is NULL */
		return (NULL);
	if (idx == 0) /* check if the index is 0 */
		return (add_dnodeint(h, n));
	tmp = *h; /* assign the head pointer to the temporary pointer */
	while (tmp != NULL) /* loop through the list until the end */
	{
		if (i == idx - 1) /* check if the counter matches the index minus one */
		{
			new = malloc(sizeof(dlistint_t)); /* allocate memory for the new node */
			if (new == NULL) /* return NULL if allocation failed */
				return (NULL);
			new->n = n; /* assign the data to the new node */
			/*set next pointer of new node to next node of temporary node*/
			new->next = tmp->next;
			new->prev = tmp; /* set prev pointer of new node to the temporary node */
			if (tmp->next != NULL) /*check if the temporary node is not the last node */
				/*set prev pointer of next node of temporary node to new node*/
				tmp->next->prev = new;
			/* set the next pointer of the temporary node to the new node */
			tmp->next = new;
			return (new);
		}
		i++; /* increment the counter */
		tmp = tmp->next; /* move to the next node */
	}
	/* check if the counter matches the index at the end of the list */
	if (i == idx)
		return (add_dnodeint_end(h, n));
	return (NULL);
}
