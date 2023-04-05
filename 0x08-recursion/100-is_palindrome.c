#include "main.h"
#include <string.h>

int is_palindrome_helper(char *s, int i, int j);

/**
 * is_palindrome -  returns 1 if a string is a palindrome and 0 if not.
 * @s: the string to be checked
 * Return: 1 and 0.
 */

int is_palindrome(char *s)
{
	if (strlen(s) <= 1)
		return (1);
	return (is_palindrome_helper(s, 0, strlen(s) - 1));
}

/**
 * is_palindrome_helper - checks if i exceeds or equals j.
 * @s: the string.
 * @i: integer initialized to 0
 * @j: initialized to strlen(s) - 1
 * Return: 0 and 1.
 */

int is_palindrome_helper(char *s, int i, int j)
{
	if (i >= j)
		return (1);
	if (s[i] != s[j])
		return (0);

	return (is_palindrome_helper(s, i + 1, j - 1));
}
