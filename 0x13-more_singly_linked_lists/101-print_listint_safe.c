#include "lists.h"

/**
 * find_loop_start - finds a loop in a linked list
 * @list: linked list to search
 * Return: address of node where loop starts/returns, NULL if no loop
 */

listint_t *find_loop_start(listint_t *list)
{
	listint_t *current, *last;

	if (list == NULL)
		return (NULL);

	for (last = list->next; last != NULL; last = last->next)
	{
		if (last == last->next)
			return (last);
		for (current = list; current != last; current = current->next)
			if (current == last->next)
				return (last->next);
	}

	return (NULL);
}

/**
 * print_listint_safe - prints a linked list, even if it
 * has a loop.
 * @head: head of list to print
 * Return: number of nodes printed
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	int loop;
	listint_t *loop_node;

	loop_node = find_loop_start((listint_t *) head);

	for (count = 0, loop = 1; (head != loop_node || loop)
			&& head != NULL; count++)
	{
		printf("[%p] %d\n", (void *) head, head->n);
		if (head == loop_node)
			loop = 0;
		head = head->next;
	}

	if (loop_node != NULL)
		printf("-> [%p] %d\n", (void *) head, head->n);

	return (count);
}
