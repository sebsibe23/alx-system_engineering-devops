#include "search_algos.h"
#include <math.h>
/**
 * jump_search - searches for a value in an array of integers
 * using the Jump search algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 * @value: value to search for
 *
 * Return: If the value is found, the function returns the index
 * of the value in the array.
 *         If the value is not found, the function returns -1.
 *
 * Description: The Jump search algorithm works by dividing the array
 * into blocks of size
 *              sqrt(size). It then jumps to the next block until it
 * finds a block containing
 *              a value that is greater than or equal to the target value.
 * Once it finds such
 *              a block, it performs a linear search within that block
 * to find the specific value.
 *              If the target value is found, the function returns the
 * index of the value in the array.
 *              If the target value is not found, the function returns -1.
 *
 *              The function verifies that the input array is not NULL and
 * that the size is greater than 0.
 *              It initializes variables to keep track of the block size (m),
 * the block index (k), the previous
 *              index (prev), and the current index (index). It then enters
 * a do-while loop to perform the jump
 *              search. Within the loop, the function prints the value
 * checked at the current index.
 *              If the value at the current index matches the target value,
 * the function returns the index.
 *              If the value at the current index is less
 * than the target value,
 * the function updates the variables
 *              to move to the next block. The loop continues until either
 * the current index exceeds the size of
 *              the array or the value at the current index is greater than
 * or equal to the target value.
 *              If the target value is not found within the loop, the function
 * prints a message indicating that the
 *              value is found between the previous and current indexes.
 * Finally,the function uses a for loop to
 *              perform a linear search within the range of indexes between the
 * previous and current indexes.
 *              It prints the value checked at each index and returns the index
 * if the value matches the target value.
 *              If the target value is not found within this range,
 * the function returns -1.
 */
int jump_search(int *array, size_t size, int value)
{
	int index, m, k, prev;
	int step, checkIndex;

	if (array == NULL || size == 0)
		return (-1);

	m = (int)sqrt((double)size);
	k = 0;
	prev = index = 0;
	step = checkIndex = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
		k++;
		prev = index;
		index = k * m;
		step++;
		checkIndex = index;
	} while (checkIndex < (int)size && array[checkIndex] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, index);

	for (; prev <= index && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
