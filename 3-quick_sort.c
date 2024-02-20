#include "sort.h"

void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
void lumuto_quick_sort(int *array, size_t low, size_t high, size_t size);
size_t lumuto_partition(int *array, size_t low, size_t high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap - Swaps two element in an array
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lumuto_partition - Lumuto partition scheme to order subset  of an array
 * of integer ascending to the last element of pivot
 * @array: Index of the low elemen
 * @high: Index of the high element.
 * @size: The size of the array.
 * Return: Index of the pivot element.
 *
 * Description: Uses the lumuto partition scheme.
 */
size_t lumuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low - 1;
	int pivot = array[high];

	for (size_t k = low; k <= high - 1; k++)
	{
		if (array[k] < pi)
		{
			i++;
			swap(&array[i], &array[k]);
			print_array(array, size);
		}
	}
	swap(&array[i], &array[high]);
	print_array(array, size);
	return (i);
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
	if (low < high)
	{
		size_t pivot = lumuto_partition(array, low, high, size);

		lumuto_quick_sort(array, low, pivot - 1, size);
		lumuto_quick_sort(array, pivot + 1, high, size);
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
	if (array == NULL || size < 2)
		return;
	lumuto_quick_sort(array, 0, size - 1, size);
}
