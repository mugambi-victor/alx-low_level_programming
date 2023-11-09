#include "lists.h"
#include <stdlib.h>

/**
* delete_dnodeint_at_index - Deletes the node at a
* given position in a dlistint_t list.
* @head: Pointer to the pointer to the head of the list.
* @index: Index of the node that should be deleted. Index starts at 0.
* Return: 1 if it succeeded, -1 if it failed.
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i;

	if (*head == NULL)
		return (-1); /* List is empty */

	/* If index is 0, delete the first node */
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* Traverse the list to find the node at the specified index */
	current = *head;
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	/* If the index is out of range, return -1 */
	if (current == NULL)
		return (-1);

	/* Update pointers to remove the node at the specified index */
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);

	return (1);
}
