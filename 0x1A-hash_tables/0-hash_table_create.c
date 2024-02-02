#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array.
 *
 * Return: a pointer to the new hash table.
 *         If an error occurs - NULL.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int lngint;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (lngint = 0; lngint < size; lngint++)
		ht->array[lngint] = NULL;

	return (ht);
}
