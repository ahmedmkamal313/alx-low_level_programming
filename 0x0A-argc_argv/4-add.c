#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main -  prints its name, followed by a new line.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 1 if error otherwise 0.
 */

int main(int argc, char *argv[])
{
	int i, num, sum = 0;

	for (i = 1; i < argc; i++)
	{
		char *arg = argv[i];

		while (*arg)
		{
			if (!isdigit(*arg))
			{
				printf("Error\n");
				return (1);
			}

			arg++;
		}

		num = atoi(argv[i]);

		if (num > 0)
		{
			sum += num;
		}
	}

	printf("%d\n", sum);
	return (0);
}
