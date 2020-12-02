#include "sort.h"

/**
 * swap - Swaps two numbers
 * @n1: First number
 * @n2: Second number
 * Return: Nothing
 */
void swap(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * sift_down - Sift down, rearrange heap
 * @array: Array
 * @start: Start index
 * @end: End index
 * @size: Size of the @array
 * Return: Nothing
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child;

	root = start;
	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(&array[root], &array[child]);
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}
/**
 * heapify - Creates heap from array
 * @array: Array
 * @size: Size of the @array
 * Return: Nothing
 */
void heapify(int *array, size_t size)
{
	int start;

	start = (size - 2) / 2;
	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Heap sort
 * @array: Array
 * @size: Size of the @array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t end = 0;

	if (!array)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}

}
