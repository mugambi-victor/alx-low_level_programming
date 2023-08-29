#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a linked list and sets the head pointer to NULL.
 * @head: A pointer to a pointer to the head node of the linked list.
 *
 * This function deallocates the memory occupied by
 * each node in the linked list,
 * starting from the head. It also sets the head pointer to NULL, effectively
 * indicating an empty list after all nodes have been freed.
 */
void free_listint2(listint_t **head)
{
	/**
	 * start at the head of the list
	 */
	listint_t *current = *head;

	listint_t *next;

	while (current != NULL)
	{
		/**
		 * store the next pointer before freeing the
		 * current node
		 */
		next = current->next;
		/**
		 * free the current node and move to the next node
		 */
		free(current);
		current = next;
	}
	/**
	 * set the head pointer to NULL to indicate an empty list
	 */
	*head = NULL;
}
