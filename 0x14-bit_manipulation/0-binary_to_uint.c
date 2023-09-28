#include "main.h"
/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @b: A pointer to the binary string to be converted.
 * Return: The equivalent unsigned integer, or 0 if the input is invalid.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);
	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);
		result = (result << 1) | (*b - '0');
		b++;
	}
	return (result);
}
