#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A pointer to the pointer to the
 * head node of the linked list.
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current != NULL)
	{
		*head = current->next;
		current->next = prev;
		prev = current;
		current = *head;
	}

	*head = prev;
	return (*head);
}
