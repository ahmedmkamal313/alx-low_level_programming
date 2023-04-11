#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * argstostr -  concatenates all the arguments of the program.
 * @ac: number of arguments.
 * @av: array of arguments.
 * Return: NULL if fail, pointer to a new string.
 */
char *argstostr(int ac, char **av)
{
	int i = 0, j = 0, len = 0;
	char *str = NULL;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			len++;
		}
		len++;
	}

	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);

	len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[len++] = av[i][j];
		}
		str[len++] = '\n';
	}
	str[len] = '\0';

	return (str);
}
