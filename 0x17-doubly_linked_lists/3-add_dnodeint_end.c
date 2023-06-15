#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: double pointer to head of the list.
 * @n: the date of the new node.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	/* declare a new and temporary node pointer */
	dlistint_t *new, *tmp;

	new = malloc(sizeof(dlistint_t)); /* allocate memoy for the new node */
	if (new == NULL) /* if the allocation failed return NULL */
		return (NULL);
	new->n = n; /* assign data to the new node */
	new->next = NULL; /*set the next pointer of the new node to NULL*/
	if (*head == NULL) /* check if the list is empty */
	{
		new->prev = NULL; /* set the prev pointer of the new node to NULL */
		*head = new; /* update the head pointer to point to the new node*/
		return (new); /* return the address of the new node */
	}
	tmp = *head; /*assign the head pointer to the temporary pointer*/
	while (tmp->next != NULL) /* loop through the list until the last node*/
		tmp = tmp->next; /*  move to the next node */
	tmp->next = new; /* set the next pointer of the last node to the new node */
	new->prev = tmp; /* set the prev pointer of the new node to the last node */
	return (new); /* return the address of the new node */
}
