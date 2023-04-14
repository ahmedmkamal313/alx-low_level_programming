#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two positive numbers.
 * @argc: the number of aurgement passed.
 * @argv: an array of pointers to the aurgement
 * Return: 0 success 98 if failed
 */

int main(int argc, char *argv[])
{
	int num1, num2, i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (98);
			}
		}
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	printf("%d\n", num1 * num2);

	return (0);
}
