#include "binary_trees.h"

/**
 * build_heap_from_array - Builds a Max Binary Heap tree from an array.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the AVL tree.
 */
heap_t *build_heap_from_array(int *array, size_t size)
{
	heap_t *root;
	size_t i;

	root = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}

	return (root);
}
