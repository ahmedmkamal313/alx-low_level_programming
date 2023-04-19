#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - Adds two integers and returns the result.
 * @a: the first integer.
 * @b: the second integer.
 * Return: the sum of a and b.
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subs two integers and returns the result.
 * @a: the first integer.
 * @b: the second integer.
 * Return: the difference of a and b.
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiply two integers and returns the result.
 * @a: the first integer.
 * @b: the second integer.
 * Return: the product of a and b.
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Devides two integers and returns the result.
 * @a: the first integer.
 * @b: the second integer.
 * Return: the result of the division of a by b.
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - mod two integers and returns the result.
 * @a: the first integer.
 * @b: the second integer.
 * Return: the remainder of the division of a by b.
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
