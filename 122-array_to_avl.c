#include "binary_trees.h"

/**
 * create_avl_from_array - Constructs an AVL tree from an array of integers.
 * @arr: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Returns: A pointer to the root node of the AVL tree, or NULL on failure.
 */
avl_t *create_avl_from_array(int *arr, size_t size)
{
	avl_t *avl_tree = NULL;
	size_t i, j;

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] == arr[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&avl_tree, arr[i]) == NULL)
				return (NULL);
		}
	}

	return (avl_tree);
}
