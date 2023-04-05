#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: the number to check.
 * Return: if no natural -1.
 */

int _sqrt_recursion(int n)
{
	int x;

	if (n == 0 || n == 1)
	{
		return (n);
	}

	x = _sqrt_recursion(n / 2);

	if (x * x == n)
		return (x);
	else
		return (-1);
}
