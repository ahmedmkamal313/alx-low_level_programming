#include "main.h"

int square(int n, int i);

/**
 * _sqrt_recursion -  returns the natural square root of a number.
 * @n: int
 * Return: whatever.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (square(n, 0));
}

/**
 * square - fint natural num
 * @n: int
 * @i: int
 * Return: what
 */

int square(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);

	return (square(n, i + 1));
}
