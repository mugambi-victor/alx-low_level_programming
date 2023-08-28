#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Prints the elements of a linked list containing integers.
 * @head: Pointer to the head node of the linked list.
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0; 

    while (h != NULL)
    {
        printf("%d\n", h->n);
        /*
        *Move to the next node
        */
        h = h->next;
        /*
        *Increment the counter
        */
        count++;
    }

    return count;
}
