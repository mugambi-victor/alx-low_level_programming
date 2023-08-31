#include <stdint.h>

/**
 * get_endianness - Determines the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	uint16_t num = 1;
	uint8_t *byte_ptr = (uint8_t *)&num;

	return (*byte_ptr);
}
