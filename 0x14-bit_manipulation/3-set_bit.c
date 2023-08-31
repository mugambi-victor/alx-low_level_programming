/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: Pointer to the unsigned long int in which to set the bit.
 * @index: The index of the bit to set (starting from 0).
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= (1UL << index);
	return (1);

}
