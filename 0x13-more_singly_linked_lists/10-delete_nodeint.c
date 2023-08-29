#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a
 * specific index in a linked list.
 * @head: A pointer to the head node of the linked list.
 * @index: The index of the node to delete (starting from 0).
 * Return: 1 if successful, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *current, *previous;

	/**
	 * list is empty
	 */
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		current = *head;
		*head = current->next;
		free(current);
		return (1);
	}

	current = *head;
	previous = NULL;

	for (i = 0; i < index && current != NULL; i++)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		/**
		 * index is out of bounds
		 */
		return (-1);

	previous->next = current->next;
	free(current);

	return (1);
}
