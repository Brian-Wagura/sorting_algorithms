#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array to be sorted
 * @size: size of the array
 *
 * Description: Implements the bubble sort algorithm to sort
 * the elements of the array in ascending order.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	size_t k;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				for (k = 0; k < size; k++)
				{
					printf("%d ", array[k]);
				}
				printf("\n");
			}
		}
	}
}
