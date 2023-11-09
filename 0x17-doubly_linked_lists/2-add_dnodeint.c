#include "lists.h"
#include <stdlib.h>

/**
* add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
* @head: Pointer to the pointer to the head of the list.
* @n: Value to be assigned to the new node.
* Return: Address of the new element, or NULL if it failed.
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL); /* Allocation failure */

	/* Initialize the new node */
	new_node->n = n;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	/* Update the next pointer of the new node to point to the current head */
	new_node->next = *head;

	/* Update the head to point to the new node */
	*head = new_node;

	return (new_node);
}
