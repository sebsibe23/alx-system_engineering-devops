#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array of integers using
 *                  binary search.
 *
 * @array: A pointer to the first element of the array to search.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: The `_binary_search` function implements the binary search
 *              algorithm to search for a value in a sorted array of integers.
 *              It takes in the input array, the starting and ending indices
 *              of the [sub]array to search, and the value to search for.
 *
 *              The function begins with a check for NULL array. If the array
 *              is NULL, it returns -1 to indicate an error.
 *
 *              The function enters a while loop that continues as long as the
 *              `right` index is greater than or equal to the `left` index.
 *              Within the loop, it prints the [sub]array being searched using
 *              `printf`. It iterates over the [sub]array and prints each
 *              element, separated by a comma, and ends the line.
 *
 *              The function calculates the middle index `i` of the [sub]array
 *              using the formula `(left + right) / 2`. It checks if the value
 *              at the middle index `i` is equal to the target value. If it is,
 *              it returns `i`.
 *
 *              If the value at the middle index `i` is greater than the target
 *              value, it updates the `right` index to `i - 1` to search in the
 *              left half of the [sub]array.
 *
 *              If the value at the middle index `i` is less than the target
 *              value, it updates the `left` index to `i + 1` to search in the
 *              right half of the [sub]array.
 *
 *              The process continues until the value is found
 * or the [sub]array
 *              becomes empty (when `right` is less than `left`).
 *
 *              If the target value is not found, it returns -1.
 *
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;
	int midValueCheck, midValue;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		midValue = array[i];
		midValueCheck = (midValue == value);

		if (midValueCheck)
			return (i);
		if (midValue > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}
/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using exponential search.
 *
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: The `exponential_search` function implements the exponential
 *              search algorithm to search for a value in a sorted array of
 *              integers. It takes in the input array, the size of the array,
 *              and the value to search for.
 *
 *              The function begins with a check for a NULL array. If the array
 *              is NULL, it immediately returns -1 to indicate an error.
 *
 *              The function checks if the first element of the array is equal
 *              to the target value. If not, it enters a for loop that starts
 *              from index 1 and continues as long as the index is less than
 *              the array size and the value at the current index is less than
 *              or equal to the target value. Within the loop, it prints the
 *              value being checked in the array using `printf`.
 *
 *              After the loop, the function calculates the value of
 * the `right`
 *              index, which is either the current index `i` or `size - 1`,
 *              whichever is smaller. It then prints a message indicating the
 *              range where the value may be found, between the index `i / 2`
 *              and `right`.
 *
 *              Finally, the function calls the `_binary_search` function to
 *              perform a binary search within the indicated range, starting
 *              from the index `i / 2` and ending at the `right` index.
 *
 *              If the `_binary_search` function returns a valid index, the
 *              `exponential_search` function also returns that index.
 *              Otherwise, it returns -1 to indicate that the value was not
 *              found in the array.
 *
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;
	int firstValueCheck, rightBound;

	if (array == NULL)
		return (-1);

	firstValueCheck = (array[0] != value);

	if (firstValueCheck)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	rightBound = (i < size);
	right = rightBound ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (_binary_search(array, i / 2, right, value));
}
