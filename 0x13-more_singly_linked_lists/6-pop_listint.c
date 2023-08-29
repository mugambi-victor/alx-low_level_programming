#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Removes and returns the first element from a linked list.
 * @head: A pointer to a pointer to the head node of the linked list.
 * Return: The value of the removed element, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	/**
	 * Default value if list is empty
	 */
	int value = 0;
	/**
	 * Check if the list is not empty
	 */
	if (*head != NULL)
	{
		/**
		 * Store the current head
		 */
		listint_t *temp = *head;
		/**
		 * Get the value of the current head
		 */
		value = temp->n;

		/**
		 * Move the head pointer to the next node
		 */
		*head = (*head)->next;
		/**
		 * Free the old head node
		 */
		free(temp);
	}

	return (value);
}
