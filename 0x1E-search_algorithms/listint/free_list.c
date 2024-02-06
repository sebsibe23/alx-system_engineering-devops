#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_list - Deallocates a singly linked list
 *
 * @list: Pointer to the linked list to be freed
 *
 * Description:
 * This function deallocates a singly linked list by
 * recursively freeing each node.
 * It takes in a pointer to the linked list as a parameter and
 * does not return a value.
 *
 * The function first checks if the list pointer is not NULL.
 * If it is NULL, there are
 * no nodes to free, so the function simply returns. Otherwise,
 * it proceeds to free
 * the nodes in the list.
 *
 * Inside the function, it creates a pointer named `node`
 * to store the next node in the list.
 * It assigns the `next` pointer of the current node to `node`
 * before freeing the current node.
 * This ensures that the reference to the next node is not lost
 *  before freeing the current one.
 *
 * After freeing the current node, the function recursively
 * calls itself with the `node` pointer
 * as the argument, effectively freeing each node in the list
 * until it reaches the end (when `node`
 * is NULL).
 *
 * The function continues to recursively free each node until
 *  the entire list is deallocated.
 */
void free_list(listint_t *list)
{
	listint_t *node;
	listint_t *nextNode;

	if (list)
	{
		nextNode = list->next;
		node = nextNode;
		free(list);
		free_list(node);
	}
}
