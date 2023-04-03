#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum.
 * @a: the array
 * @size: the size of the array.
 */

void print_diagsums(int *a, int size)
{
	int i = 0, j = size - 1, sum0 = 0, sum1 = 0;

	while (i <= (size * size))
	{
		sum0 += a[i];
		i += size + 1;
	}
	while (j < (size * size - 1))
	{
		sum1 += a[j];
		j += size - 1;
	}
	printf("%d, %d\n", sum0, sum1);
}
