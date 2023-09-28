#include <stdio.h>

int get_endianness(void)
{
	unsigned int num = 1;
	char *byte = (char *)&num;
	/**
	 * If the least significant byte is 1, the system is Little Endian (returns 1)
	 * If the most significant byte is 1, the system is Big Endian (returns 0)
	 */
	return (*byte == 1);
}
