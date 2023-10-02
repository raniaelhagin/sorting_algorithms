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
 * bubble_sort - Sorts an array of numbers ascending
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (length > 1)
	{
		i = 1;
		while (i < length)
		{
			if (array[i - 1] > array[i])
			{
				swap(array + i - 1, array + i);
				print_array(array, size);
			}
			i++;
		}
		length -= 1;
	}
}
