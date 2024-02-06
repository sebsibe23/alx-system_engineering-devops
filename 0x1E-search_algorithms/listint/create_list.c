#include <stdlib.h>
#include "../search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - Creates a singly linked list from an array
 *
 * @array: Pointer to the array used to fill the list
 * @size: Size of the array
 *
 * Return: Pointer to the head of the created list (NULL on failure)
 *
 * Description:
 * This function creates a singly linked list
 * by iterating over the input array.
 * It takes in a pointer to the array and the size of the array as parameters.
 * The function returns a pointer to
 * the head of the created list if successful;
 * otherwise, it returns NULL.
 *
 * The function initializes the list pointer to NULL.
 * It then enters a while loop to iterate over the array elements.
 * Inside the loop, it dynamically allocates memory for a new node.
 * If the allocation fails, it calls the `free_list`
 * function to free the previously
 * allocated nodes and returns NULL.
 *
 * The function assigns the value of the
 * current array element to the `n` member of the node.
 * It assigns the current index (size - 1) to the `index` member of the node.
 * It sets the `next` pointer of the node to the current head of the list.
 * Finally, it updates the head of the list to the new node.
 *
 * After iterating over all the array elements,
 * the function returns the head of the list.
 * If the array is empty or NULL, the function returns NULL.
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int nodeValue, nodeIndex;

	list = NULL;
	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_list(list);
			return (NULL);
		}
		nodeValue = array[size];
		nodeIndex = size;

		node->n = nodeValue;
		node->index = nodeIndex;
		node->next = list;
		list = node;
	}
	return (list);
}
