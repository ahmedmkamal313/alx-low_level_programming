#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the head of the list.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp; /* declare a temporary node pointer */

	while (head != NULL) /* loop through the list until the end */
	{
		tmp = head; /* assign the head pointer to the temporary pointer */
		head = head->next; /* move the head pointer to the next node */
		free(tmp); /* free the temporary node */
	}
}
