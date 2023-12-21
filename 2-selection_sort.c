#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using Selection sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k, min_index;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		for (; j < size; ++j)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int temp = array[i];

			array[i] = array[min_index];
			array[min_index] = temp;

			k = 0;
			for (; k < size; ++k)
			{
				printf("%d ", array[k]);
			}
			printf("\n");
		}
		i++;
	}
}
