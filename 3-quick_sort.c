#include "sort.h"

/**
 * _swap - Swaps two integers
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
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;
	size_t k;

	j = low;
	for (; j <= high - 1; ++j)
	{
		if (array[j] <= pivot)
		{
			++i;
			_swap(&array[i], &array[j]);

			k = 0;
			while (k < size)
			{
				printf("%d ", array[k]);
				++k;
			}
			printf("\n");
		}
	}

	_swap(&array[i + 1], &array[high]);

	k = 0;
	for (; k < size; ++k)
	{
		printf("%d ", array[k]);
	}
	printf("\n");

	return ((size_t)(i + 1));
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, (ssize_t)pivot_index - 1, size);
		quick_sort_recursive(array, (ssize_t)pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	ssize_t low = 0;
	size_t i;
	ssize_t high = (ssize_t)size - 1;

	if (array == NULL || size < 2)
	{
		return;
	}


	printf("Initial array: ");

	i = 0;
	for (; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	quick_sort_recursive(array, low, high, size);

	printf("Sorted array: ");

	i = 0;
	for (; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
