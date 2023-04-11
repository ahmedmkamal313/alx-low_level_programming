#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array
 * of integers
 * @width: width of grid.
 * @height: height of grid.
 * Return: pointer to 2D array of integers, NULL if fail
 */

int **alloc_grid(int width, int height)
{
	int **arr = NULL, i = 0, j = 0;

	arr = malloc(sizeof(int *) * height);

	if (width <= 0 || height <= 0)
		return (NULL);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		arr[i] = malloc(sizeof(int) * width);
		if (arr[i] == NULL)
		{
			while (--i >= 0)
			{
				free(arr[i]);
			}
			free(arr);
			return (NULL);
		}
		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}
	return (arr);
}
