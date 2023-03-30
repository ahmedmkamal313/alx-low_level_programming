#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer.
 * @size: the size
 */

void print_buffer(char *b, int size)
{
	int i, j, k;

	k = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (k < size)
	{
		j = size - k < 10 ? size - k : 10;
		printf("%08x: ", k);
		for (i = 0; i < 10; i++)
		{
			if (i < j)
				printf("%02x", *(b + k + i));
			else
				printf("  ");
			if (i % 2)
			{
				printf(" ");
			}
		}
			for (i = 0; i < j; i++)
			{
				int c = *(b + k + i);

				if (c < 32 || c > 132)
				{
					c = '.';
				}
				printf("%c", c);
			}
			printf("\n");
			k += 10;
	}
}
