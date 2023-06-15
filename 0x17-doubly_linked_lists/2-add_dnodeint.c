#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the list.
 * @n: the data of the new node.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new; /* declare a new node pointer */

	new = malloc(sizeof(dlistint_t)); /* allocate memory for the new node */
	if (new == NULL) /* check if allocation failed */
		return (NULL);
	new->n = n; /* assign the data to the new node */
	new->prev = NULL; /* set the previous pointer of the nod to null */
	new->next = *head; /*set next pointer of new node to the current head */
	if (*head != NULL) /* check if the list is not empty */
		(*head)->prev = new; /*set prev pointer of current head to the new node*/
	*head = new;
	return (new);
}
