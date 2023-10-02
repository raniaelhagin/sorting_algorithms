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
 * selection_sort - Sorts an array of numbers using selection sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
	{
		return;
	}

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min = array + i;
		while (j < size)
		{
			if (*min > array[j])
			{
				min = array + j;
			}
			j++;
		}

		if (min != (array + i))
		{
			swap(array + i, min);
			print_array(array, size);
		}
		i++;
	}
}
