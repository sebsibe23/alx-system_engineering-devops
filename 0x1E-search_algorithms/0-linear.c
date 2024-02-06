#include "search_algos.h"

/**
 * linear_search - Linear search algorithm to search for a value in an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of the value if found, -1 otherwise.
 */
int linear_search(int *array, size_t size, int value)
{
	int i;
	int temp_value;

	if (array == NULL)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		temp_value = array[i];
		printf("Value checked array[%u] = [%d]\n", i, temp_value);
		if (value == temp_value)
			return (i);
	}
	return (-1);
}
