#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: Double pointer to the head of the list
 * Description: This function sorts a double linked list of integers
 * in ascending order using the insertion sort algorithm.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *back;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		back = current->prev;
	
		while (prev != NULL && current->n < prev->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;

			if (current->prev == NULL)
				*list = current;

			print_list((const listint_t *)*list);

			prev = back->prev;
		}

		current = current->next;

	}
}

/**
 * Swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @head: The pointer to the head of the doubly-linked list.
 * @prev: The pointer to the first node to swap.
 * @current: Pointer to the second node to swap
 */
void swap_nodes(listint_t **head, listint_t *current, listint_t **prev)
{
	while (current->prev != NULL && current->n < current->prev->n)
	{
		(*prev)->next = current->next;
		if (current->next != NULL)
			current->next->prev = *prev;
		current->prev = (*prev)->prev;
		current->next = *prev;

		if ((*prev)->prev != NULL)
			(*prev)->prev->next = current;
		else
			*head = current;

		(*prev)->prev = current;
		*prev = current->prev;

		print_list((const listint_t *)*head);
	}
}
