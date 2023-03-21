#include "main.h"

/**
 * _abs - betty loves us.
 * @n: the int to be absolute value computed.
 * Return: -n for neg, n for pos.
 */

int _abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
