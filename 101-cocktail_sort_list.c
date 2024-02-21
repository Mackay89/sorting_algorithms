#include "sort.h"



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

	/*forwad pass*/
	for (tail = *list; tail->next != NULL; tail = tail->next)
	{
	       if (tail->n > tail->next->n)
	       {
		       swap_nodes(tail, tail->next);
		       swap = 1;
		       print_list(*list);
	       }
	}

	/* if no swaps occurred, the list is sorted */
	if (!swap)
		break;

	swap = 0;

	/* Backward pass */
	for (; tail->prev != NULL; tail = tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			swap = 1;
			print_list(*list);
		}
	}
	
	} while (swap);
}

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
