#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a dlistint_t list.
 * @h: Pointer to the pointer to the head of the list.
 * @idx: Index where the new node should be added. Index starts at 0.
 * @n: Value to be assigned to the new node.
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current;
    unsigned int i;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL; /* Allocation failure */

    /* Initialize the new node */
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    /* If the list is empty and index is not 0, return NULL */
    if (*h == NULL && idx != 0)
    {
        free(new_node);
        return NULL;
    }

    /* If index is 0, insert at the beginning */
    if (idx == 0)
    {
        new_node->next = *h;
        if (*h != NULL)
            (*h)->prev = new_node;
        *h = new_node;
        return new_node;
    }

    /* Traverse the list to find the node before the specified index */
    current = *h;
    for (i = 0; i < idx - 1 && current != NULL; i++)
        current = current->next;

    /* If the index is out of range, return NULL */
    if (current == NULL)
    {
        free(new_node);
        return NULL;
    }

    /* Update pointers to insert the new node at the specified index */
    new_node->next = current->next;
    new_node->prev = current;
    if (current->next != NULL)
        current->next->prev = new_node;
    current->next = new_node;

    return new_node;
}