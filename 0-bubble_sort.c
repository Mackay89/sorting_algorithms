#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sort an array of integers in acending order.
 * @array: The pointer to the array to be sorted.
 * @size: The size of the array.
 * Return: Nothing
 * Describtion: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
		swap--;
	}
}
