#include <stdlib.h>
#include "hash_tables.h"

/**
* hash_table_create - Creates a hash table
* @size: The size of the array
*
* Return: A pointer to the newly created hash table, or NULL if an error occurs
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned long int i;

	/* Allocating memory for the hash table structure */
	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	/* Allocating memory for the array of hash_node_t pointers */
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	/* Initialize each element of the array to NULL */
	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;

	/* Setting the size of the hash table */
	hash_table->size = size;

	return (hash_table);
}
