#include "binary_trees.h"

/**
 * create_avl_from_sorted_array_recursive - Helper function for creating AVL from sorted array
 * @array: The input array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the newly created node
 */
avl_t *create_avl_from_sorted_array_recursive(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new_node = calloc(1, sizeof(avl_t));

	if (!new_node)
		return (NULL);

	new_node->n = array[mid];
	new_node->parent = parent;
	new_node->left = create_avl_from_sorted_array_recursive(array, start, mid - 1, new_node);
	new_node->right = create_avl_from_sorted_array_recursive(array, mid + 1, end, new_node);

	return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: The input array
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (create_avl_from_sorted_array_recursive(array, 0, size - 1, NULL));
}
