#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of integers using
 *                        the Interpolation search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 *
 * Description: The Interpolation search algorithm is an improved variant of
 *              binary search, especially for uniformly distributed arrays. It
 *              estimates the position of the target value by interpolating
 *              between the first and last elements. It performs a binary
 *              search-like approach to narrow down the search range until the
 *              target value is found or the search range becomes empty.
 *
 *              The function checks if the input array is NULL. It initializes
 *              variables `low` and `high` to represent the indices of the
 *              first and last elements of the array. It enters a while loop
 *              while the `size` variable is non-zero. Within the loop, it
 *              calculates the probable position `pos` using interpolation. It
 *              prints the value checked at the current index. If `pos` is out
 *              of range, it prints an error message and breaks the loop. If
 *              the value at `pos` is equal to the target value, it returns
 *              `pos`. If the value at `pos` is less than the target value,
 *              `low` is updated to `pos + 1` to search in the upper half.
 *              If the value at `pos` is greater, `high` is updated to
 *              `pos - 1` to search in the lower half. The process continues
 *              until the value is found or the search range becomes empty.
 *              If the target value is not found, it returns -1.
 *
 * Note: The code assumes a sorted array and does not handle unsorted arrays
 *       or non-uniformly distributed elements.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low, high;
	double f;
	int rangeCheck, valueCheck;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;
	rangeCheck = valueCheck = 0;
	while (size)
	{
		f = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
		pos = (size_t)(low + f);
		printf("Value checked array[%d]", (int)pos);
		rangeCheck = (pos >= size);
		valueCheck = (array[pos] == value);
		if (rangeCheck)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[pos]);
		}
		if (valueCheck)
			return ((int)pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;

		if (low == high)
			break;
	}

	return (-1);
}
