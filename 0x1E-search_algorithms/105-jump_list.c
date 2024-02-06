#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in a singly linked
 * list using the Jump search algorithm
 *
 * @list: input list
 * @size: size of the list
 * @value: value to search for
 *
 * Return: pointer to the node containing the value,
 * or NULL if not found
 *
 * Description:
 * This function performs a jump search on a singly linked list.
 * It takes in the input list,
 * the size of the list, and the value to search for.
 * The function returns a pointer to the
 * node containing the value if found; otherwise, it returns NULL.
 *
 * The function first checks for edge cases where the list is empty or NULL.
 * Then, it calculates
 * the jump step size, 'm', as the square root of the list size.
 * It initializes the index, 'k', to 0.
 *
 * The function enters a do-while loop that continues as long as
 * the current index is less than
 * the list size and the current node's value is less than the target value.
 * Within the loop,
 * it keeps track of the previous node encountered and updates the
 * index by multiplying 'k' with 'm'.
 * It traverses the list until it reaches a node whose index is greater than
 * or equal to the updated index.
 *
 * After exiting the loop, the function prints the range of indexes
 * within which the value could be found.
 * It then iterates over the nodes between the previous node and
 * the current node and checks if any of
 * the node's values match the target value. If a match is found,
 * the function returns a pointer to that node.
 *
 * If the target value is not found within the list, the function returns NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, k, m;
	listint_t *prev;
	int indexValueCheck, indexValue;

	if (list == NULL || size == 0)
		return (NULL);

	m = (size_t)sqrt((double)size);
	index = 0;
	k = 0;

	do {
		prev = list;
		k++;
		index = k * m;

		while (list->next && list->index < index)
			list = list->next;

		if (list->next == NULL && index != list->index)
			index = list->index;

		indexValue = list->n;
		printf("Value checked at index [%d] = [%d]\n", (int)index, indexValue);

		indexValueCheck = (indexValue < value);
	} while (index < size && list->next && indexValueCheck);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
