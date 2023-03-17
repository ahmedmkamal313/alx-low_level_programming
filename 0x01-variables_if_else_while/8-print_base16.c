#include <stdio.h>

/**
 *main - print alphabet in new line.
 *Return: Always 0
 */

int main(void)
{
	int n;
	int al;

	for (n = '0' ; n <= '9' ; n++)
	{
		putchar(n);
	}

	for (al = 'a' ; al <= 'f' ; al++)
	{
		putchar(al);
	}

	putchar('\n');

	return (0);
}
