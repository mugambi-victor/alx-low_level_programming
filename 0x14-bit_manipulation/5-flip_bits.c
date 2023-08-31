/**
 * flip_bits - Calculates the number of bits
 * needed to flip to transform n to m.
 * @n: First unsigned long int.
 * @m: Second unsigned long int.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result != 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);

}
