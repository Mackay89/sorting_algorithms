#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The number of elements in the array
 * Description: This fuction prints each element of an array of integer
 * seperate by the comma and space, follewed by a new line. 
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
