#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers.
 * @a: the array.
 * @n: the elements.
 */

void reverse_array(int *a, int n)
{
	int i, j;

	for(j = n - 1; j >= n / 2; j--)
	{
		i = a[n - 1 - j];
		a[n - 1 - j] = a[j];
		a[j] = i;
	}
}
