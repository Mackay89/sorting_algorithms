#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * 			using the insertion sort algorithm.
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; 

	for listint_t *current = (*list)->next;
	{
		listint_t *back = current->prev;
		
	}
}

/**
 * Swap_nodes - Swap two nodes ina listint_ doubly-linked list.
 * @head: The pointer to the head of the doubly-linked list.
 * @prev: The pointer to the first node to swap.
 * @current: The second node to swap
 */
void swap_nodes(listint_t **head, listint_t *current, listint_t **prev)
{
	while (current->prev != NULL && current->next < current->prev->next)
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

