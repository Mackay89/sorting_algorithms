#include "sort.h"

/**
 * selection_sort - Sorts an array of integerrs in ascending order using the
 * selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_index, temp;


	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = &array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min_index)
				min_index = &array[j];
		}
		if (&array[i] != min_index)
		{
			temp = (array[i]);
			array[i] = *min_index;
			*min_index = temp;
			print_array(array, size);
		}
	}
}

/**
 * swap_ ints - Swaps two the integer in an array.
 * @a: Pointer to the first integer to swap
 * @b: Pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
