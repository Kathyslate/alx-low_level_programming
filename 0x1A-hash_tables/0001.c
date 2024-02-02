#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_function - Creates a hash table key and size
 * @size: The size of the array.
 * @key: key of hash function
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
unsigned long int hash_function(const char *key, unsigned long int size)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *key++) != '\0')
		hash = ((hash << 5) + hash) + c;

	return (hash % size);
}

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t **table;

	if (size == 0)
		return (NULL);

	table = malloc(sizeof(_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (unsigned long int i = 0; i < size; i++)
		table->array[i] = NULL;

	return (table);
}
