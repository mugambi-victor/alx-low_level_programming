#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
* shash_table_create - Creates a sorted hash table
* @size: The size of the array
*
* Return: A pointer to the newly created sorted hash table
*/
shash_table_t *shash_table_create(unsigned long int size)
{

	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
* shash_table_set - Inserts or updates a key/value in a sorted hash table
* @ht: The sorted hash table
* @key: The key string
* @value: The value string
*
* Return: 1 if success, 0 otherwise
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Check if the key already exists, and update the value if it does */
	current_node = ht->shead;
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			/* Update the value and return success */
			free(current_node->value);
			current_node->value = strdup(value);
			if (current_node->value == NULL)
				return (0);
			return (1);
		}
		current_node = current_node->snext;
	}

	/* Key doesn't exist, create a new node */
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	/* Insert the new node in the sorted list at the right place */
	if (ht->shead == NULL || strcmp(ht->shead->key, key) >= 0)
	{
		new_node->snext = ht->shead;
		new_node->sprev = NULL;
		if (ht->shead != NULL)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		current_node = ht->shead;
		while (current_node->snext != NULL && strcmp(current_node->snext->key, key) < 0)
			current_node = current_node->snext;

		new_node->snext = current_node->snext;
		new_node->sprev = current_node;
		if (current_node->snext != NULL)
			current_node->snext->sprev = new_node;
		current_node->snext = new_node;
	}

	return (1);
}

/**
* shash_table_get - Retrieves a value associated with a key in a sorted hash table
* @ht: The sorted hash table
* @key: The key to search for
*
* Return: The value associated with the element, or NULL if key couldn’t be found
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Traverse the sorted list to find the key */
	current_node = ht->shead;
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value); /* Key found, return the associated value */
		current_node = current_node->snext;
	}

	/* Key not found */
	return (NULL);
}

/**
* shash_table_print - Prints a sorted hash table
* @ht: The sorted hash table
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");
	current_node = ht->shead;
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
* shash_table_print_rev - Prints a sorted hash table in reverse order
* @ht: The sorted hash table
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");
	current_node = ht->stail;
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
* shash_table_delete - Deletes a sorted hash table
* @ht: The sorted hash table
*/
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current_node, *temp_node;

	if (ht == NULL)
		return;

	current_node = ht->shead;
	while (current_node != NULL)
	{
		temp_node = current_node->snext;
		free(current_node->key);
		free(current_node->value);
		free(current_node);
		current_node = temp_node;
	}

	free(ht->array);
	free(ht);
}
