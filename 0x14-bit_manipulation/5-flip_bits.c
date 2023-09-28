/**
 * flip_bits - counts the number of bits needed to flip to get from n to m
 * @n: the first number
 * @m: the second number
 * Return: the number of bits to flip
 */
unsigned int flip_bits(unsigned int n, unsigned int m)
{
	unsigned int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result != 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}
	return (count);
}
