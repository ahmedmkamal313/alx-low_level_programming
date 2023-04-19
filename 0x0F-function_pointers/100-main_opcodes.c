#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: argc
 * @argv: argv
 * Return: 1, 2 ,0
 */

int main(int argc, char **argv)
{
	int num_bytes, i;
	int (*add)(int, char **) = main;
	unsigned char op;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);
	if (num_bytes <= 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < num_bytes; i++)
	{
		op = *(unsigned char *)add;
		printf("%02x", op);

		if (i == num_bytes - 1)
			continue;
		printf(" ");

		add++;
	}

	printf("\n");
	return (0);
}
