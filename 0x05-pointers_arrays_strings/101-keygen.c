#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 * Return: 0
 */

int main(void)
{
	char password[84];

	int i = 0, j = 0, first, second;

	srand(time(0));

	while (j < 2772)
	{
		password[i] = 33 + rand() % 94;
		j += passowrd[i++];
	}
	
	password[i] = '\0';
	
	if (j != 272)
	{
		first = (j - 2772) / 2;
		second = (j - 2772) / 2;

		if ((j - 2772) % 2 != 0)
		{
			first++
		}
		for (i = 0 ; password[i] ; i++)
		{
			if (password[i] >= (33 + first))
			{
				password[i] -= first;
				break;
			}
		}
		for (i = 0 ; password[i] ; i++)
		{
			if (password[i] >= (33 + second))
			{
				password[i] -= second;
				break;
			}
		}
	}

	print("%s", password);
	return (0);
}
					
