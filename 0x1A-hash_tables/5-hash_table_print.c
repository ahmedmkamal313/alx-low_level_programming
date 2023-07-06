#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	int flag = 0;

	/* Check if the parameter is valid */
	if (ht == NULL)
		return;

	/* Print the opening curly brace */
	printf("{");

	/* Loop through the array of the hash table */
	for (i = 0; i < ht->size; i++)
	{
		/* Traverse the linked list at each index */
		current = ht->array[i];
		while (current != NULL)
		{
			/* Print a comma and a space if needed */
			if (flag == 1)
			printf(", ");

			/* Print the key and value pair */
			printf("'%s': '%s'", current->key, current->value);

			/* Set the flag to indicate that a pair has been printed */
			flag = 1;

			/* Move to the next node */
			current = current->next;
		}
	}

	/* Print the closing curly brace and a new line */
	printf("}\n");
}
