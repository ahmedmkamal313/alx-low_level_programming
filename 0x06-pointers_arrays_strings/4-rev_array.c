#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers.
 * @a: the array.
 * @n: the elements.
 */

void reverse_array(int *a, int n)
{
	int i;
	int arr[n];

	for (i = 0 ; i < n ; i++)
	{
		arr[n - 1 - i] = a[i];
	}
	for (i = 0 ; i < n ; i++)
	{
		a[i] = arr[i];
	}
}
