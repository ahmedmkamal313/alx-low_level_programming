#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head of the list.
 * @index: index of the node, starting at 0.
 * Return: pointer to the nth node, or NULL if it does not exist.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	for (i = 0; i < index && head != NULL; i++)
		head = head->next;

	return (head);
}
