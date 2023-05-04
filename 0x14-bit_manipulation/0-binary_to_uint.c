#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: to be converted
 * Return:  the converted number, or 0 if fail.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i])
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		num = (num << 1) + (b[i] - '0');
		i++;
	}

	return (num);
}
