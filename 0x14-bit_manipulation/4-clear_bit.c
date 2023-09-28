#include <stdio.h>

/**
 * clear_bit - clears the value of a bit at a given index (sets it to 0)
 * @n: pointer to the number to modify
 * @index: the index of the bit to clear
 * Return: 1 if successful, or -1 if an error occurs
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n & ~(1UL << index);
	return (1);
}
