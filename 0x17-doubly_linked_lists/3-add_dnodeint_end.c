#include "lists.h"
#include <stdlib.h>

/**
* add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
* @head: Pointer to the pointer to the head of the list.
* @n: Value to be assigned to the new node.
* Return: Address of the new element, or NULL if it failed.
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *current;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL); /* Allocation failure */

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, the new node is also the head */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Find the last node in the list */
	current = *head;
	while (current->next != NULL)
		current = current->next;

	/* Update pointers to add the new node at the end */
	current->next = new_node;
	new_node->prev = current;

	return (new_node);
}
