#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: ponter to pointer to the head of the list.
 * Return: the number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow, *fast;

	if (head == NULL)
		exit(98);

	slow = head;
	fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			break;
		}
	}

	return (count);
}
