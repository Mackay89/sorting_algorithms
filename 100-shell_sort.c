#include "sort.h"

void swap_ints(int *a, int *b);
void shell_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the shell sort algorithm with the Knuth sequence.
 * @array: The array of integers be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, k, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3;)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			j = k;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(&array[j], &array[j - gap]);
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
