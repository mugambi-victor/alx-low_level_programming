#include "lists.h"

/**
 * get_nodeint_at_index - Retrieves a node at
 * a specific index in a linked list.
 * @head: A pointer to the head node of the linked list.
 * @index: The index of the desired node (starting from 0).
 * Return: A pointer to the node at the specified index, or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/**
	 * Initialize count to keep track of position
	 * and current pointer.
	 */
	unsigned int count = 0;
	listint_t *current = head;

	/**
	 * Traverse the list until the end
	 * is reached or the index is found.
	 */
	while (current != NULL)
	{
		/**
		 * Check if the current count
		 * matches the specified index.
		 */
		if (count == index)
			/**
			 * Return the node at the specified index
			 */
			return (current);

		/**
		 * Move to the next node and increment the count.
		 */
		current = current->next;
		count++;
	}
	/**
	 * Index out of bounds or the list is empty
	 */
	return (NULL);
}
