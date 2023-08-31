#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: Pointer to a binary string.
 *
 * Return: Converted unsigned int or 0 if invalid characters are present.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (*b)
	{
		char c = *b;
		/**
		 * Return 0 for any character otjer than 0 or 1
		 */
		if (c != '0' && c != '1')
		{
			char *b = NULL;

			return (0);
		}

		/**
		 * convert the character to a number
		 * and add it to the result
		 */
		result = result * 2 + (c - '0');
		b++;
	}

	return (result);

}
