#ifndef LISTS_H
#define LISTS_H
#include <stddef.h>

/*
*LISTS_H file contains all function prototypes for functions used in more linked lists project.
*/
typedef struct listint_t
{
    int *n;
    unsigned int len;
    struct listint_t *next;
} listint_t;
size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *add_nodeint_end(listint_t **head, const int n);

#endif // LISTS_H
