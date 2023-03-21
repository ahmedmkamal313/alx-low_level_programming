#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercas.
 */

void print_alphabet_x10(void)
{
	int alph;
	int count = 0;

	while (count++ <= 9)
	{
		for (alph = 'a' ; alph <= 'z' ; alph++)
			_putchar(alph);

		_putchar('\n');
	}
}
