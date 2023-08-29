#include "lists.h"

/**
 * sum_listint - Calculates the sum of elements in a linked list.
 * @head: A pointer to the head node of the linked list.
 * Return: The sum of the elements, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
