#include "sort.h"

void quick_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void lumuto_quick_sort(int *array, size_t low, size_t high, size_t size);
size_t lumuto_partition(int *array, size_t low, size_t high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two element in an array
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lumuto_partition - Order subset  of an array of integers acoording to
 * the lomutu partition scheme
 * @array: Index of the low elemen
 * @high: Index of the high element.
 * @size: The size of the array.
 * Return: To the final partition index.
 */
size_t lumuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t j, k;

	if ((low >= high) || (array == NULL))
		return (0);

	pivot = array[high];
	j = low;
	for (k = low; k < high; k++)
	{
		if (array[k] <= pivot)
		{
			if (j != k)
			{
				swap_ints(&array[j], &array[k]);
				print_array(array, size);
			}
			j++;
		}
		if (j != high)
		{
			swap_ints(&array[j], &array[high]);
			print_array(array, size);
		}
	}
	return (j);
}

/**
 * lumuto_quick_sort - Recursively sorts an array of integers using
 * the quick sort algorithm.
 * @array: The index of the low element.
 * @high: The index of the high element.
 * @size: The size of the array.
 */
void lumuto_quick_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lumuto_partition(array, low, high, size);
		if (pivot_index > 0)
		{
			if (pivot_index > low)
				lumuto_quick_sort(array, low, pivot_index - 1, size);
			if (pivot_index < high)
				lumuto_quick_sort(array, pivot_index + 1, high, size);
		}
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the quick sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		lumuto_quick_sort(array, 0, size - 1, size);
	}
}

