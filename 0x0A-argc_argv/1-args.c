#include <stdio.h>
#include <stdlib.h>

/**
 * main -  prints its name, followed by a new line.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}
