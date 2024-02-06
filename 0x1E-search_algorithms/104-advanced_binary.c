#include "search_algos.h"

/**
 * rec_search - searches for a value in an array of
 * integers using the Binary search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 *
 * Return: index of the number, or -1 if not found
 *
 * Description:
 * This function performs a recursive binary search
 * ona sorted array of integers.
 * It takes in the input array, the size of the array,
 * and the value to search for.
 * The function returns the index of the value if found;
 * otherwise, it returns -1.
 *
 * The function starts by checking
 * for edge cases where the array is empty or NULL.
 * Then, it prints the content of the array being searched.
 *
 * The function calculates the midpoint of the array.
 * If the midpoint element is equal
 * to the value being searched,
 * the function checks if there are duplicate elements
 * before the midpoint. If there are,
 * it recursively calls itself on the left half of
 * the array (including the midpoint)
 * to find the leftmost occurrence of the value.
 *
 * If the value is less than the midpoint element,
 * the function recursively calls itself
 * on the left half of the array (including the midpoint)
 * to continue the search.
 *
 * If the value is greater than the midpoint element,
 * the function recursively calls itself
 * on the right half of the array (excluding the midpoint)
 * to continue the search.
 *
 * The function continues to divide
 * the array in half until it finds the value or determines
 * that the value is not present in the array.
 * It returns the index of the value if found,
 * or -1 if not found.
 */
int rec_search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;
	int halfValueCheck, halfValue;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	halfValue = array[half];
	halfValueCheck = (halfValue == value);

	if (halfValueCheck)
	{
		if (half > 0)
			return (rec_search(array, half + 1, value));
		return ((int)half);
	}

	if (value < array[half])
		return (rec_search(array, half + 1, value));

	half++;
	return (rec_search(array + half, size - half, value) + half);
}




/**
 * advanced_binary - calls to rec_search to return
 * the index of the number
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 *
 * Return: index of the number, or -1 if not found
 *
 * Description:
 * This function serves as a wrapper for the `rec_search` function. It takes in
 * the input array, the size of the array,
 * and the value to search for. It calls
 * the `rec_search` function to perform
 * a binary search on the array and returns
 * the index of the value if found; otherwise, it returns -1.
 *
 * The function first calls `rec_search`
 * and assigns the returned index to the `index`
 * variable. It then checks if the index is valid
 * and if the element at that index is
 * equal to the value being searched. If not,
 * it means the value was not found, so the
 * function returns -1.
 *
 * If the value is found, the function returns the index of the value.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = rec_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
