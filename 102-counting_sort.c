#include "sort.h"
#include <stdlib.h>

/**
 * largest_number - finds largest number in an array
 * @array: given array
 * @size: array's size
 *
 * Return: largest number
 */
int largest_number(int *array, size_t size)
{
	int max;
	size_t i;

	if (!array)
		return (0);

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - sorts array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Description: this function sorts an array of integers
 * in increasing order using the Counting sort algorithm
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int range, i, val;
	int *counting_arr, *tmp_arr;

	if (!array || (size == 1))
		return;

	/* set up counting array */
	range = largest_number(array, size);
	counting_arr = malloc(sizeof(int) * (++range));
	if (!counting_arr)
		return;
	for (i = 0; i < range; i++)
		counting_arr[i] = 0;

	for (i = 0; i < (int)size; i++)
		counting_arr[array[i]]++;

	for (i = 0; i < (range - 1); i++)
		counting_arr[i + 1] += counting_arr[i];
	print_array(counting_arr, range);

	/* sort elements and copy to original array */
	tmp_arr = malloc(sizeof(int) * size);
	if (!tmp_arr)
	{
		free(counting_arr);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		val = array[i];
		tmp_arr[(counting_arr[val]--) - 1] = val;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = tmp_arr[i];

	free(counting_arr);
	free(tmp_arr);
}
