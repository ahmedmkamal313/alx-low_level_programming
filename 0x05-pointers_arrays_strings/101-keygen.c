#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 * Return: 0.
 */

int main()
{
	int i;
	char password[10];

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		password[i] = rand() % 26 + 'a';
	}
	password[10] = '\0';
	printf("%s\n", password);
	return (0);
}
