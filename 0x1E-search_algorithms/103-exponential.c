#include "search_algos.h"

void print_array(int *array, size_t low, size_t high);
int bin_search(int *array, size_t low, size_t high, int value);

/**
 * exponential_search - Searches for a value in a sorted array
 * of integers using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value located, or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, low, high;

	if (array == NULL || size == 0)
		return (-1);

	i = 1;
	while (i < size && array[i] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i *= 2;
	}
	low = i / 2;
	high = i < size ? i : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (bin_search(array, low, high, value));
}

/**
 * bin_search - Searches for a value in a sorted array of integers using the
 * Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @low: The lower bound of the subarray to search in
 * @high: The upper bound of the subarray to search in
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int bin_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (array == NULL)
		return (-1);

	while (low <= high)
	{
		print_array(array, low, high);
		mid = (low + high) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
		high = mid - 1;
	}

	return (-1);
}

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @low: The lower bound of the subarray to print
 * @high: The upper bound of the subarray to print
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}
