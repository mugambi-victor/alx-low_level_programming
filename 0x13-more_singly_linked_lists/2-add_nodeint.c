#include <stdlib.h>
#include "lists.h" 

/**
 * add_nodeint - Adds a new node with an integer value to the beginning of a linked list.
 * @head: Pointer to a pointer to the head node of the linked list.
 * @n: Integer value to be stored in the new node.
 * Return: The address of the new node, or NULL if allocation fails.
 */
listint_t *add_nodeint(listint_t **head, int n)
{
    listint_t *new_node;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}
