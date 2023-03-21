#include <stdio.h>
void print_alphabet();

/**
 * main - check code
 * Return: always 0
 */

int main(void)
{
	print_alphabet();
	return (0);
}
/**
 * print_alphabet - print alphabet
 * Return: void
 */
void print_alphabet()
{
	int alph;
	for(alph = 'a' ; alph <= 'z' ; alph++)
	    putchar(alph);
	
	putchar('\n');
}
