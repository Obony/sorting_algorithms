#include "sort.h"

/**
* swap_values -	Swaps values from two different array indexes
* @array:       Array to swap values from
* @i:           value under index (i) to swap
* @j:           value under index (j) to swap
* @size:        size of the array
*/
void swap_values(int *array, int i, int j, int size)
{
	int copy_num = 0;

	copy_num = array[i];
	array[i] = array[j];
	array[j] = copy_num;
	print_array(array, size);
}

/**
* lomuto_partition -    Partitions array into two parts based on pivot
* @array:				Array to partition.
* @low:                 value in the lowest index
* @high:                value in the highest index
* @size:                size of the array
* Return:              Returns two partitions based on partition value
*/
int lomuto_partition(int *array, int low, int high, int size)
{
	int i = 0, j = 0, pivot = 0;

	pivot = array[high];

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != i)
				swap_values(array, j, i, size);
			i++;
		}
	}
	if (i != high)
		swap_values(array, i, high, size);
	return (i);
}

/**
* recursive_partition - Helper function for Quick Sort
* @array:				Array to be partitioned
* @low:                 index to low element
* @high:                index to high element
* @size:                size of the array
*/
void recursive_partition(int *array, int low, int high, int size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		recursive_partition(array, low, pivot - 1, size);
		recursive_partition(array, pivot + 1, high, size);
	}
}


/**
* quick_sort -  Sorts an array with the Quicksort Algorithm
* @array:       Array to be sorted
* @size:        Size of the array
* Return:       Sorted array in asending order
*/
void quick_sort(int *array, size_t size)
{
	size_t low = 0, high = 0;

	high = (size - 1);

	recursive_partition(array, low, high, size);
}
