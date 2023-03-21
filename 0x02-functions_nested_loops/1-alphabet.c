#include "main.h"

/**
 *  print_alphabet - print the alphabet, in lowercase.
 *  Return: void
 */

void print_alphabet(void)
{
	int alph;

	for (alph = 'a' ; alph <= 'z' ; alph++)
		putchar(alph);

	putchar('\n');
}
