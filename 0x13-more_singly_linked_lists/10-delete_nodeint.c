#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a
 * listint_t linked list.
 * @head: pointer to pointer to the head of the list.
 * @index: index of the node that should be deleted.
 * Return: 1 if succeeded, -1 if failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node, *next_node, *del_node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		del_node = *head;
		*head = (*head)->next;
		free(del_node);
		return (1);
	}

	prev_node = *head;
	for (i = 0; i < index - 1 && prev_node != NULL; i++)
		prev_node = prev_node->next;

	if (prev_node == NULL || prev_node->next == NULL)
		return (-1);

	del_node = prev_node->next;
	next_node = del_node->next;
	prev_node->next = next_node;
	free(del_node);

	return (1);
}
