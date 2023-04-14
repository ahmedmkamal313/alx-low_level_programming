#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _isdigit - checks if charater is digit
 * @s: char to be checked.
 * Return: 0 if fail, 1 otherwise
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to checked
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * print_error - print error.
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments passed to the program.
 * @argv: array of pointer to arguments
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, num1, num2, *result, i, res = 0, carry;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !_isdigit(s1) || !_isdigit(s2))
		print_error();
	len1 = _strlen(s1), len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		num1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			num2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (num1 * num2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			res = 1;
		if (res)
			_putchar(result[i] + '0');
	}
	if (!res)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
