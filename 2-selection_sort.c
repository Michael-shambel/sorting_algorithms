#include "sort.h"
/**
 * swap - a function that is needed to swap two elements
 * @array: function of the array to be swapped
 * @i: the first element to be swapped
 * @j: the second element to be swaapped
 */
void swap(int *array, size_t i, size_t j)
{
	size_t temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * selection_sort - a function to sort an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min_index;

	if (array == NULL || size < 2)
		return;

	for (; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (i != min_index)
		{
			swap(array, i, min_index);
			print_array(array, size);
		}
	}
}
