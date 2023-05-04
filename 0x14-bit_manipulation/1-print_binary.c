#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		printf("0");
		return;
	}

	print_binary(n >> 1);

	printf("%lu", n & 1);
}
