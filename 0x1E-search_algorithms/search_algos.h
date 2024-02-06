#ifndef _SORTING_ALGOS_H_
#define _SORTING_ALGOS_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Singly linked list node
 *
 * @n: Integer value stored in the node
 * @index: Index of the node in the list
 * @next: Pointer to the next node in the list
 *
 * Description: Node structure for a singly linked
 * list used in sorting algorithms.
 *              Each node contains an integer value,
 * an index, and a pointer to the next node.
 */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list node with an express lane
 *
 * @n: Integer value stored in the node
 * @index: Index of the node in the list
 * @next: Pointer to the next node in the list
 * @express: Pointer to the next node in the express lane
 *
 * Description: Node structure for a singly linked list with
 * an express lane, used in sorting algorithms.
 *              Each node contains an integer value, an index,
 * and pointers to the next node and the next node in the express lane.
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/**
 * linear_search - Searches for a value in an array using
 * linear search algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index where the value is found, or -1 if the value is not present.
 */
int linear_search(int *array, size_t size, int value);

/**
 * binary_search - Searches for a value in a sorted
 * array using binary search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index where the value is found,
 * or -1 if the value is not present.
 */
int binary_search(int *array, size_t size, int value);

/**
 * jump_search - Searches for a value in
 * a sorted array using jump search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index where the value is found,
 * or -1 if the value is not present.
 */
int jump_search(int *array, size_t size, int value);

/**
 * interpolation_search - Searches for a value in
 * a sorted array using interpolation search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index where the value is found,
 * or -1 if the value is not present.
 */
int interpolation_search(int *array, size_t size, int value);

/**
 * exponential_search - Searches for a value in
 * a sorted array using exponential search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index where the value is found,
 * or -1 if the value is not present.
 */
int exponential_search(int *array, size_t size, int value);

/**
 * advanced_binary - Searches for the first occurrence of
 * a value in a sorted array using binary search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index where the value is found,
 * or -1 if the value is not present.
 */
int advanced_binary(int *array, size_t size, int value);

/**
 * jump_list - Searches for a value in
 * a singly linked list using jump search algorithm.
 *
 * @list: Pointer to the head node of the linked list.
 * @size: Number of elements in the list.
 * @value: Value to search for in the list.
 *
 * Return: Pointer to the node where the value is found,
 * or NULL if the value is not present.
 */
listint_t *jump_list(listint_t *list, size_t size, int value);

/**
 * linear_skip - Searches for a value in
 * a singly linked list with an express
 * lane using linear search algorithm.
 *
 * @list: Pointer to the head node of the linked list.
 * @value: Value to search for in the list.
 *
 * Return: Pointer to the node where the value is found,
 * or NULL if the value is not present.
 */
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
