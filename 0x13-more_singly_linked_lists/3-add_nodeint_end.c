#include <stdlib.h>
#include "lists.h"  

/**
 * add_nodeint_end - Adds a new node with an integer value to the end of a linked list.
 * @head: Pointer to a pointer to the head node of the linked list.
 * @n: Integer value to be stored in the new node.
 * Return: The address of the new node, or NULL if allocation fails.
 */
listint_t *add_nodeint_end(listint_t **head, int n)
{
    listint_t *new_node, *current;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        /**
	 * If the list is empty, set the new node as the head
	 **/
        *head = new_node;
    }
    else
    {
        /** 
	 * Traverse to the end of the list
	 */
        current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        /**
	 *  Append the new node to the end
	 */
        current->next = new_node;
    }

    return (new_node);
}
