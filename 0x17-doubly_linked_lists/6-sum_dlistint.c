#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data of a dlistint_t
 * @head: pointer to the head of the list
 * Return: the som of the data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0; /* declare a sum variable */

	while (head != NULL) /* loop through the list until the end */
	{
		sum += head->n; /* add the data of the current conde to the sum */
		head = head->next; /* move to the next node */
	}
	return (sum);
}
