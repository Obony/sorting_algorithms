#include "sort.h"
#include <stdio.h>

void build_max_heap(int *, size_t);
void sift_down(int *, size_t, size_t);
void heapify(int *, size_t, size_t, size_t);
void swap(int *, size_t, size_t, size_t);

/**
 * heap_sort - sorts array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Description: this function sorts an array of integers
 * in increasing order using the Heap sort algorithm
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array)
		return;

	build_max_heap(array, size);
	for (i = size; i > 1; i--)
		sift_down(array, i, size);
}

/**
 * build_max_heap - rearrange array elements to create a max heap
 * @array: given array
 * @size: array's size
 *
 * Return: void
 */
void build_max_heap(int *array, size_t size)
{
	int i;

	if (!array)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);
}

/**
 * sift_down - implement sift down algorithm to sort array
 * @array: given array
 * @size: current array's size
 * @arr_s: actual array's size
 *
 * Return: void
 */
void sift_down(int *array, size_t size, size_t arr_s)
{
	if (!array)
		return;

	/* swap first and last element */
	swap(array, arr_s, 0, size - 1);

	/* rearrange elements */
	heapify(array, size - 1, 0, arr_s);
}

/**
 * heapify - compare root with its children and swap if necessary
 * @array: given array
 * @size: current array's size
 * @index: current root
 * @arr_s: actual array's size
 *
 * Return: void
 */
void heapify(int *array, size_t size, size_t index, size_t arr_s)
{
	size_t largest, l, r;

	if (!array || index >= size)
		return;

	/* find largest element in subtree*/
	largest = index;

	l = 2 * index + 1;
	if (l < size && array[l] > array[largest])
		largest = l;

	r = 2 * index + 2;
	if (r < size && array[r] > array[largest])
		largest = r;

	/* swap and heapify again if root is not largest */
	if (index != largest)
	{
		swap(array, arr_s, index, largest);
		heapify(array, size, largest, arr_s);
	}

}

/**
 * swap - swaps two elemtents of an array
 * @array: given array
 * @size: array's size
 * @i: first element's index
 * @j: second element's index
 *
 * Return: void
 */
void swap(int *array, size_t size, size_t i, size_t j)
{
	int tmp;

	if (!array || i >= size || j >= size)
		return;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;

	print_array(array, size);
}
