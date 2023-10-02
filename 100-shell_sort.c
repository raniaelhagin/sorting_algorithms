#include "sort.h"

/**
 * shell_sort - implements shell sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int n = 1, i, tmp, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (n < (int)size / 3)
		n = (3 * n) + 1;

	while (n > 0)
	{
		i = n;
		while (i < (int)size)
		{
			tmp = array[i];
			j = i;
			while ((j >= n) && (array[j - n] > tmp))
			{
				array[j] = array[j - n];
				j = j - n;
			}
			array[j] = tmp;
			i++;
		}
		print_array(array, size);
		n = (n - 1) / 3;
	}
}
