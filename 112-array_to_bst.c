#include "binary_trees.h"

/**
 * array_to_bst - Constructs a Binary Search Tree (BST) from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * This function iterates through each element in the array and inserts it into
 * the BST. If a value in the array already exists in the tree, it is ignored.
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	/* Initialize the root of the BST to NULL */
	bst_t *root = NULL;
	size_t i;

	/* Iterate through each element in the array */
	for (i = 0; i < size; i++)
	{
		/* Insert the current element into the BST */
		bst_insert(&root, array[i]);
	}

	/* Return a pointer to the root node of the created BST */
	return (root);
}
