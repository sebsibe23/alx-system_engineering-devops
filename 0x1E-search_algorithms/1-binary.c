#include "search_algos.h"
/**
 * binary_search - Searches for a value in
 * a sorted array of integers using binary search.
 *
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the
 * array is NULL, returns -1.
 *         Otherwise, returns the index
 *         where the value is located.
 *
 * Description: This function implements the binary search
 * algorithm to efficiently locate
 *              a given value within a sorted array.
 *              The array is assumed to be sorted in
 *              ascending order. If the value is found,
 *              the function returns the index where
 *              it is located. If the value is not present or
 *              the array is NULL, the function
 *              returns -1.
 *
 *              The function also prints the [sub]array
 *              being searched after each change.
 *              This can be useful for debugging and
 *              understanding the progress of the search.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, left, right;
	int mid_value;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		mid_value = array[i];
		if (mid_value == value)
			return (i);
		if (mid_value > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}
