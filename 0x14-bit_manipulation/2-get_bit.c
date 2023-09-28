#include <stdio.h>

/**
 * get_bit - gets the value of a bit at a given index
 * @n: the number to extract the bit from
 * @index: the index of the bit to retrieve
 * Return: the value of bit at specified index, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((int)((n >> index) & 1));
}
