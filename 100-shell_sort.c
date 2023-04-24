#include "sort.h"

/**
 * swap - swaps two values of array
 * @array: the array
 * @i: first element's index
 * @j: second element's index
 *
 * Return: void
 */
void swap(int *array, long int i, long int j)
{
	int tmp;

	if (!array)
		return;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * shell_sort - sorts array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Description: this function sorts an array of integers
 * in increasing order using the Shell sort algorithm
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	long int h, next, i, j;

	if (array == NULL || (size == 1))
		return;

	h = next = 1;
	while ((size_t)next < size)
	{
		h = next;
		next = (h * 3) + 1;
	}

	while (h >= 1)
	{
		for (j = h; (size_t)j < size; j++)
		{
			for (i = j - h; i >= 0; i -= h)
			{
				if (array[i] > array[i + h])
					swap(array, i, i + h);
				else
					break;
			}
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
