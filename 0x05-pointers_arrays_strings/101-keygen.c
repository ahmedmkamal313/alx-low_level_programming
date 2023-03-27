#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * main -  generates random valid passwords for the program 101-crackme.
 * Return: 0.
 */

int main(void)
{
	int i;
	char key[10];

	srand(time(NULL));

	for (i = 0 ; i < 10 ; i++)
	{
		key[i] = (rand() % 94) + 33;
	}

	key[9] = '\0';
	printf("%s\n", key);

	return (0);
}
