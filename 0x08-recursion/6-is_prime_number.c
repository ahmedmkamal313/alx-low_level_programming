#include "main.h"

int is_prime_helper(int n, int i, int w);

/**
 * is_prime_number - if integer is a prime number, otherwise return 0.
 * @n: integer to check.
 * Return: 1 and 0.
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	if (n % 2 == 0 || n % 3 == 0)
		return (0);

	return (is_prime_helper(n, 5, 2));

}

/**
 * is_prime_helper - help the main.
 * @n: the int.
 * @i: int
 * @w: int
 * Return: prime_helper.
 */

int is_prime_helper(int n, int i, int w)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);

	return (is_prime_helper(n, i + w, 6 - w));
}
