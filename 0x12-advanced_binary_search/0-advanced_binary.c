#include "search_algos.h"

/**
 * _advanced_binary - finds first occurence of element in array
 * @original: pointer
 * @array: array to array
 * @size: size of size
 * @value: value to value
 * Return: index of value
 */
int _advanced_binary(int *original, int *array, size_t size, int value)
{
	size_t mid = (size - 1) / 2, i = 0;

	if (size < 1)
		return (-1);
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d%s", array[i], i < size - 1 ? ", " : "\n");

	if (!mid && *array >= value)
		return (*array == value ? array - original : -1);
	else if (array[mid] >= value)
		return (_advanced_binary(original, array, mid + 1, value));
	return (_advanced_binary(original, array + mid + 1, size - mid - 1, value));
}


/**
 * advanced_binary - finds first occurence of element in array
 * @array: array to search
 * @size: size of size
 * @value: value to value
 * Return: index of index
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (_advanced_binary(array, array, size, value));
}
