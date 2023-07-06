#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *tmp;

	/* Check if the parameter is valid */
	if (ht == NULL)
		return;

	/* Loop through the array of the hash table */
	for (i = 0; i < ht->size; i++)
	{
		/* Traverse the linked list at each index */
		current = ht->array[i];
		while (current != NULL)
		{
			/* Save the next node */
			tmp = current->next;

			/* Free the key and value strings */
			free(current->key);
			free(current->value);

			/* Free the node */
			free(current);

			/* Move to the next node */
			current = tmp;
		}
	}

	/* Free the array */
	free(ht->array);

	/* Free the hash table struct */
	free(ht);
}
