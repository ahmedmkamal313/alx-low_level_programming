#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98.
 * @n: number.
 */

void print_to_98(int n)
{
	int i;

	for (i = n ; i <= 98 ; i++)
	{
		int ones = i % 10;
		int tens = (i / 10) % 10;

		if (tens > 0)
			putchar(tens + '0');

		putchar(ones + '0');

		if (i < 98)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
}
