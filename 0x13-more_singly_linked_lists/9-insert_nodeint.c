#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a
 * new node at a specific index in a linked list.
 * @head: A pointer to the head node of the linked list.
 * @idx: The index at which the new node should be inserted.
 * @n: The value to be assigned to the new node.
 * Return: The address of the new node, or NULL on failure.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	/**
	 * index counter
	 */
	unsigned int i;
	/**
	 * pointers for a new node and traversal
	 */
	listint_t *new_node, *current;
	/**
	 * Create a new node
	 */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	/**
	 * insert at the beginning
	 */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	/**
	 * Traverse to the node before the insertion point
	 */
	current = *head;
	for (i = 0; i < idx - 1 && current != NULL; i++)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}
	/**
	 * Insert the new node
	 */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
