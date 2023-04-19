#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - the entry.
 * @argc: argv.
 * @argv: argv.
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	int (*op)(int, int);
	int num1, num2;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (argv[2][1])
	{
		printf("Error\n");
		exit(99);
	}

	op = get_op_func(argv[2]);

	if (op == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	printf("%d\n", op(num1, num2));
	return (0);
}
