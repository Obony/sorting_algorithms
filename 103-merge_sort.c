#include "sort.h"

/**
* merge_sort - Sort an array of integers in ascending
*               order using the merge sort algorithm.
* @array:       An array of integers
* @size:        The size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	array_split_recursive(array, buffer, 0, size);

	free(buffer);
}


/**
* array_split_recursive -   Splits array till size equals to one then
*                           remerges it back in ascending order
* @subarr:                  A subarray of an array of integers to sort
* @buffer:                  A buffer to store the stored result.
* @front:                   The front index of the subarray
* @back:                    The back index of the subarray
*/
void array_split_recursive(int *subarr, int *buffer, size_t front, size_t back)
{
	size_t mid_point;

	if (back - front > 1)
	{
		mid_point = front + (back - front) / 2;
		array_split_recursive(subarr, buffer, front, mid_point);
		array_split_recursive(subarr, buffer, mid_point, back);
		merge_subarr(subarr, buffer, front, mid_point, back);
	}
}


/**
* merge_subarr -    Sorts subarray of integers
* @subarr:          A subarray of an array of integers to sort.
* @buffer:          A buffer to store the sorted subarray
* @front:           The front index of the array
* @mid_point:       The middle index of the array
* @back:            The back index of the array
*/
void merge_subarr(int *subarr, int *buffer, size_t front, size_t mid_point,
size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid_point - front);

	printf("[right]: ");
	print_array(subarr + mid_point, back - mid_point);

	for (i = front, j = mid_point; i < mid_point && j < back; k++)
		buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid_point; i++)
		buffer[k++] = subarr[i];
	for (; j < back; j++)
		buffer[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}
