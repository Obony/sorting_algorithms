#include "sort.h"

/**
 * selection_sort - sorts array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Description: this function sorts an array of integers
 * in increasing order using the Selection sort algorithm
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (!array)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		/* find least element in sublist */
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[min] > array[j])
				min = j;

		/* place it at the beginning of sublist */
		if (i != min)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
