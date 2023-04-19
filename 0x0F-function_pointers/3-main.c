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
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = get_op_func(argv[2]);

	if (!op)
	{
		printf("Error\n");
		exit(99);
	}

	if (op  == NULL || argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", op(num1, num2));
	return (0);
}
