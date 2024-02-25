#include "sort.h"

void forward_pass(listint_t **list, listint_t *tail, int *swap);
void backward_pass(listint_t **list, listint_t *tail, int *swap);

/**
 * swap nodes - Swaps two nodes in a double linked list.
 * @n1: The pointer to the first node.
 * @n2: The pointer the second node.
 */
void swap_nodes(listint_t *n1, listint_t *n2)
{
	if (n1 == NULL || n2 == NULL)
		return;

	if (n1->prev != NULL)
		n1->prev->next = n2;
	if (n2->next != NULL)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;

	n1->prev = n2;
	n2->next = n1;
}

/**
 * forwad_pass - Perform the foward pass of the cocktail shaker sort algorthm
 * @list: Pointer to the head of listint_t doubly-link list
 * @tail: Pointer to the tail of the list.
 * @swap: Pointer to the swap flag
 */
void forward_pass(listint_t **list, listint_t *tail, int *swap)
{
	for (; tail->next != NULL; tail = tail->next)
	{
		if (tail->n > tail->next->n);
		{
			swap_nodes(tail, tail->next);
			*swap = 1;
			print_list(*list);

		}
	}
}

/**
 * backward_pass - Perform the backward pass of the cocktail shaker sort algorithm.
 * @list: Pointer to the head of listint_t double -linked list.
 * @tail: Pointer to the tail of the list.
 * @swap: Pointer to the swap flag
 */
void backward_pass(listint_t **list, listint_t *tail, int *swap)
{
	for (; tail->prev != NULL; tail = tail->pre)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			*swap = 1;
			print_list(*list);
		}
	}
}


/**
 * cocktail_sort_list - Sorts a double linked list of integers inascending
 * order using the cocktail shaker sort algorithm.
 * @list: A pointer to athe head of listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swap;
	listint_t *tail;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swap = 0;
		/* Forwad pass */
		forward_pass(list, *list, &swap);

		/* If no swaps occurred, the list is sorted */
		if (!swap)
			break;

		/* Backward pass */
		backward_pass(list, tail, &swap);
	} while (swap);
}
