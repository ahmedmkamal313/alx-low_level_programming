#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index index of dlistint_t list.
 * @head: pointer to the head of the list.
 * @index: the index of the node that should be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp; /* declare a temporary node pointer */
	unsigned int i = 0; /* declare a counter variable */

	/* return -1 if the list is NULL */
	if (head == NULL || *head == NULL)
		return (-1);
	tmp = *head; /* assign head pointer to the tmp pointer */
	if (index == 0) /* check if the index is 0 */
	{
		*head = tmp->next; /* update head pointer to next node*/
		/*if the list isn't empty set prev pointer to the new node*/
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp); /*free the temp node*/
		return (1);
	}
	while (tmp != NULL) /* loop through the list until the end */
	{
		if (i == index) /* check if the counter matches the index */
		{
			/* set next pointer of the previous node to next node of temporary node*/
			tmp->prev->next = tmp->next;
			/* if the tmp node is not the last set prev poitner of tmp to prev node */
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			free(tmp); /* free the temporary node */
			return (1);
		}
		i++; /* increment the counter*/
		tmp = tmp->next; /* move to the next node */
	}
	return (-1);
}
