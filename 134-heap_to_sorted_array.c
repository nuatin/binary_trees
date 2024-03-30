#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of
 * integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int extracted_value;
	size_t heap_size;
	size_t i = 0;

	if (!heap)
		return (NULL);

	heap_size = binary_tree_size(heap);
	*size = heap_size;

	array = malloc(heap_size * sizeof(int));
	if (!array)
		return (NULL);

	while (heap)
	{
		extracted_value = heap_extract(&heap);
		array[i++] = extracted_value;
	}

	return (array);
}
