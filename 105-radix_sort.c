#include "sort.h"
#include <stdlib.h>

#define BASE 10

void count_sort(int *, size_t, int);
int largest_number(int *array, size_t size);

/**
 * radix_sort - sorts array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Description: this function sorts an array of integers
 * in increasing order using the Radix sort algorithm
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, i;

	if (!array || (size == 1))
		return;

	max = largest_number(array, size);
	for (i = 1; (max / i) > 0; i *= BASE)
	{
		count_sort(array, size, i);
		print_array(array, size);
	}
}

/**
 * count_sort - sorts an array according to LSD
 * @array: given array
 * @size: array's size
 * @place: to get digit to be sorted according to
 *
 * Return: void
 */
void count_sort(int *array, size_t size, int place)
{
	int count[BASE], d;
	int *tmp;
	long int i;

	if (!array)
		return;

	/* set up counting array */
	for (i = 0; i < BASE; i++)
		count[i] = 0;
	for (i = 0; (size_t)i < size; i++)
	{
		d = (array[i] / place) % BASE;
		count[d]++;
	}
	for (i = 1; i < BASE; i++)
		count[i] += count[i - 1];

	/* sort elements and copy to original array */
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	for (i = size - 1; i >= 0; i--)
	{
		d = (array[i] / place) % BASE;
		tmp[(count[d]--) - 1] = array[i];
	}
	for (i = 0; (size_t)i < size; i++)
		array[i] = tmp[i];
	free(tmp);
}

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
