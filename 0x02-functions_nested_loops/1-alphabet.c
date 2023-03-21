#include <stdio.h>

/**
 * main - check the code
 * Return: Always 0
 */

int main(void)
{
	print_alphabet();
	return (0);
}

/**
 *  print_alphabet - print the alphabet, in lowercase.
 *  Return: 0
 */

int print_alphabet(void)
{
	int alph;

	for (alph = 'a' ; alph <= 'z' ; alph++)
	{
		putchar(alph);
	}

	putchar('\n');
}
