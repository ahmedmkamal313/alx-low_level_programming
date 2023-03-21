#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98.
 * @n: number.
 */

void print_to_98(int n)
{
	int i;

	for (i = n ; i <= 98 ; i++)
	{
		if (i == 98)
			printf("%d\n", i);

		else
			printf("%d, ", i);
	}
}
