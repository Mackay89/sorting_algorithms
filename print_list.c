#include "sort.h"
#include <stdio.h>

/**
  * print_list - Prints a list of integers
 * @list: Pointerto the head of the list
 * Description: The function prints the elements of a linked lis
 * separated by commas and spaces, followed by the a new line.
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
