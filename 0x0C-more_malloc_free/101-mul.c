#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multip 2 positive numbers.
 * @argc: the number of arguments passed.
 * @argv: an array of pointers to the arguments.
 * Return: 0 on success, 98 on fail.
 */

int main(int argc, char *argv[])
{
	char *num1 = strlem(num1), *num2 = strlen(num1);
	int len1 = argv[1], len2 = argv[2], *restult, i, sum, carry, k = 0, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}
	while (k < len1 + len2 && result[k] == 0)
		k++;
	if (k == len1 + len2)
	{
		printf("0\n");
		free(result);
		return (0);
	}
	for (; k < len1 + len2; k++)
		printf("%d", result[k]);
	printf("\n");
	free(result);
	return (0);
}
