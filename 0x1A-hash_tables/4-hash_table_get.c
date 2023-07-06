#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to look for
 * Return: The value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	/* Check if the parameters are valid */
	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	/* Get the index of the key using the key_index function */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at the index and look for the key */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			/* Return the value if the key is found */
			return (current->value);
		}
		current = current->next;
	}

	/* Return NULL if the key is not found */
	return (NULL);
}
