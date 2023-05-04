#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: a pointer to the number to be modified.
 * @index: the index of the bit to be clear.
 * Return: 1 if it worked, or - 1 if error.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(*n) * 8)
		return (-1);

	mask = ~(1UL << index);
	*n &= mask;

	return (1);
}
