#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the head of the list.
 * Return: the address of the node where the loop starts,
 * or NULL if no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
		return (NULL);

	slow = head;
	fast = head->next;
	while (slow != fast)
	{
		if (fast == NULL || fast->next == NULL)
			return (NULL);
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return (slow);
}
