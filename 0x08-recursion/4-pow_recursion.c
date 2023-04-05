#include "main.h"

/**
 * _pow_recursion - value of x raised to the power of y.
 * @x: first int
 * @y: second int
 * Return: if less 0 -1.
 */

int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	else if (y < 0)
		return (-1);
	else
		return (x * _pow_recursion(x, y - 1));
}
