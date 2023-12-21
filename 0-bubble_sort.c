#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * _swap - This Function Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - This Sorts an array of integers in
 * ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		for (; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
		i++;
	}
}
