#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees all nodes of a linked list containing integer values.
 * @head: Pointer to the head node of the linked list.
 */
void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);  // Free the current node
    }
}
