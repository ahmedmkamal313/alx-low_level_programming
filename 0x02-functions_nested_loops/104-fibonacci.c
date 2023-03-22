#include <stdio.h>

/**
  * main - Prints the first 98 fibonacci numbers
  *
  * Return: always 0.
  */

int main(void)
{
	int first = 1;
	int second = 2;
	int next, i;

	printf("%d, %d", first, second);

	for (i = 3 ; i <= 98 ; i++)
	{
		next = first + second;
		printf(", %d", next);
		first = second;
		second = next;
	}

	printf("\n");
	return (0);
}
