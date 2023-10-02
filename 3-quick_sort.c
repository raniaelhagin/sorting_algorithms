#include "sort.h"

/**
 * swap - Swap two numbers in an array.
 * @num1: The first number to swap.
 * @num2: The second number to swap.
 */
void swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * lomuto_partition - get partitions
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: Low index
 * @high: high index
 *
 * Return: pivot
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	/* choose the last element as the pivot*/
	int *p, left = low, right = low;
	p = array + high;

	while (left < right)
	{
		if (array[left] < *p)
		{
			if (right < left)
			{
				swap(array + left, array + right);
				print_array(array, size);
			}
			right++;
		}
		left++;
	}

	if (array[right] > *p)
	{
		swap(array + right, p);
		print_array(array, size);
	}

	return (right);
}

/**
 * lomuto_sort - implement the quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: Low index
 * @high: high index
 *
 * Return: Nothing
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low >= high || low < 0)
		return;

	pivot = lomuto_partition(array, size, low, high);

	/* sort partitions */
	lomuto_sort(array, size, low, pivot - 1); /* left side*/
	lomuto_sort(array, size, pivot + 1, high);
}

/**
 * quick_sort - Sorts an array of numbers using quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	lomuto_sort(array, size, 0, size - 1);
}
