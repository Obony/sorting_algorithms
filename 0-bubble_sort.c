nclude "sort.h"

/**
 * swap_values - Swaps two integers in array.
 * @x: First integer to swap.
 * @z: Second integer to swap.
 */
void swap_values(int *x, int *z)
{
	int tmp;

	tmp = *x;
	*x = *z;
	*z = tmp;
}
/**
 * bubble_sort - Sorts an array containing integers ascending order.
 * @array: An array of integers to be sorted.
 * @size: The size of array.
 *
 * Description: Prints array after every swap being done.
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, current_size = size;
	bool is_sorted = false;

	if (array == NULL || size < 2)
		return;

	while (is_sorted == false)
	{
		is_sorted = true;
		for (index = 0; index < current_size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap_values(array + index, array + index + 1);
				print_array(array, size);
				is_sorted = false;
			}
		}
		current_size--;
	}
}
