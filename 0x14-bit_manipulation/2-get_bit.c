#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: the number to be examined.
 * @index: the index of the bit to be returned.
 * Return: the value of the bit at index, -1 if error.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	n >>= index;
	return (n & 1);
}
