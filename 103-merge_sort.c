#include "sort.h"

void _merge_srt(int *array, int *temp, size_t size);

/**
 * merge_sort - Merge sort
 *
 * @array: Array to be sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	_merge_srt(array, temp, size);
	free(temp);
}

/**
 * _merge_srt - initiate merge sort
 *
 * @array: array to be sorted
 * @temp: temporary array for holding sorted elements
 * @size: size of the array
 */
void _merge_srt(int *array, int *temp, size_t size)
{
	size_t half = size / 2, i = 0, j = 0, k;

	if (size < 2)
		return;

	_merge_srt(array, temp, half);
	_merge_srt(array + half, temp + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);

	for (k = 0; k < size; k++)
		if (j >= size - half || (i < half && array[i] < (array + half)[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = (array + half)[j];
			j++;
		}
	for (k = 0; k < size; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array, size);
}
