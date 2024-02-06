#include <stdio.h>
#include "../search_algos.h"

/**
 * print_list - Prints the content of a listint_t
 *
 * @list: Pointer to the head of the list
 *
 * Description:
 * This function prints the content of
 * a singly linked list of type `listint_t`.
 * It takes in a pointer to the head of the list as
 * a parameter and does not return a value.
 *
 * The function starts by printing
 * a header line indicating that it is printing a list.
 * It then enters a while loop that iterates
 * over each node in the list.
 *
 * Inside the loop, it uses `printf` to print the index and
 * value of the current node.
 * It uses the `index` member of the node to print
 * the position (starting from 0)
 * and the `n` member to print the value.
 *
 * After printing the index and value of the current node,
 * it moves to the next node
 * by updating the `list` pointer with the `next`
 * pointer of the current node.
 *
 * The loop continues until it reaches the end of
 * the list (when `list` becomes NULL),
 * at which point it prints a newline character to
 * separate the list from other output.
 *
 * Overall, the function provides a convenient
 * way to print the content of a list for
 * debugging or informational purposes.
 */
void print_list(const listint_t *list)
{
	const listint_t *currentNode;
	int nodeValue;
	size_t nodeIndex;

	printf("List:\n");
	currentNode = list;

	while (currentNode)
	{
		nodeValue = currentNode->n;
		nodeIndex = currentNode->index;
		printf("Index[%lu] = [%d]\n", nodeIndex, nodeValue);
		currentNode = currentNode->next;
	}
	printf("\n");
}

