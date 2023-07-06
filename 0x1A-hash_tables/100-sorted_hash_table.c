#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 * Return: A pointer to the newly created hash table,
 * or NULL if something went wrong
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	/* Allocate memory for the hash table struct */
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	/* Initialize the size and array fields */
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	/* Set all the array elements to NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	/* Initialize the shead and stail fields to NULL */
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key
 * @value: The value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new, *current, *tmp;

	if (ht == NULL || key == NULL || value == NULL || strlen(key) == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (0);
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new->key);
		free(new);
		return (0);
	}
	new->next = ht->array[index];
	ht->array[index] = new;
	new->sprev = NULL;
	new->snext = NULL;
	if (ht->shead == NULL)
	{
		ht->shead = new;
		ht->stail = new;
		return (1);
	}
	current = ht->shead;
	while (current != NULL && strcmp(current->key, key) < 0)
		current = current->snext;
	if (current == NULL)
	{
		new->sprev = ht->stail;
		ht->stail->snext = new;
		ht->stail = new;
		return (1);
	}
	if (current == ht->shead)
	{
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
		return (1);
	}
	new->sprev = current->sprev;
	new->snext = current;
	current->sprev->snext = new;
	current->sprev = new;
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to look for
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

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

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int flag = 0;

	/* Check if the parameter is valid */
	if (ht == NULL)
		return;

	/* Print the opening curly brace */
	printf("{");

	/* Traverse the sorted linked list from head to tail */
	current = ht->shead;
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
		current = current->snext;
	}

	/* Print the closing curly brace and a new line */
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	int flag = 0;

	/* Check if the parameter is valid */
	if (ht == NULL)
		return;

	/* Print the opening curly brace */
	printf("{");

	/* Traverse the sorted linked list from tail to head */
	current = ht->stail;
	while (current != NULL)
	{
		/* Print a comma and a space if needed */
		if (flag == 1)
			printf(", ");

		/* Print the key and value pair */
		printf("'%s': '%s'", current->key, current->value);

		/* Set the flag to indicate that a pair has been printed */
		flag = 1;

		/* Move to the previous node */
		current = current->sprev;
	}

	/* Print the closing curly brace and a new line */
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *tmp;

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
