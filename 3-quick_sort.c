#include "sort.h"

void quicksort_recursive(int *array, int low, int high);
int partition(int array[], int low, int high);
void print_sort(int array[], size_t size, int init);
void swap(int *a, int *b);

/**
 * quick_sort - Function that sorts an array based
 * on quicksort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size  < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}
/**
 * quicksort_recursive - Recursive function to perform quicksort
 *
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 * Return: void
 */
void quicksort_recursive(int *array, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quicksort_recursive(array, low, pi - 1);
		quicksort_recursive(array, pi + 1, high);
	}
}
/**
 * partition - Function that sets pivot for quicksort
 *
 * @array: Array to partition
 * @low: Starting index of the array
 * @high: Ending index of the array
 * Return: Partition index
 */
int partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);
	return (i + 1);
}

/**
 * print_sort - Function that prints as it should
 *
 * @array: Array to be printed
 * @size: Size of array
 * @init: Should initialize array
 * Return: 0
 */
void print_sort(int array[], size_t size, int init)
{
	static int *p = (void *)0;
	static size_t s;

	if (!p && init)
	{
		p = array;
		s = size;
	}
	if (!init)
		print_array(p, s);
}
/**
 * swap - Function that swaps two values
 *
 * @a: First value
 * @b: Second value
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
