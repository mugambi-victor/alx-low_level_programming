#include "lists.h"

/**
 * reverse_listint - Reverses the order of
 * elements in a linked list.
 * @head: A pointer to the head node of the linked list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next;

	while (current != NULL)
	{
		/**
		 * Store the next node and reverse the link
		 */
		next = current->next;
		current->next = prev;
		/**
		 * Move prev and current forward
		 */
		prev = current;
		current = next;
	}

	/**
	 * Update the head to point tO
	 * the new first node (previously last node)
	 */
	*head = prev;

	return (*head);
}
