#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - sorts array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Description: this function sorts an array of integers
 * in increasing order using the Bubble sort algorithm
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	swapped = 1;
	for (i = 0; i < (size - 1) && swapped; i++)
	{
		swapped = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swap the two elements */
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
