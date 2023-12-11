#include "search_algos.h"

void print_array(int *array, size_t low, size_t high);
int binary_search_recursive(int *array, size_t low, size_t high, int value);

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using the advanced binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}

/**
 * binary_search_recursive - Searches for a value in a sorted array of integers
 * using the binary search algorithm recursively
 * @array: Pointer to the first element of the array to search in
 * @low: The lower bound of the subarray to search in
 * @high: The upper bound of the subarray to search in
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = (low + high) / 2;
	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		else
			return (binary_search_recursive(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (binary_search_recursive(array, mid + 1, high, value));
	else
		return (binary_search_recursive(array, low, mid - 1, value));
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
