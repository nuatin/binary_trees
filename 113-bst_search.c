#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the BST to search.
 * @value: Value to search for in the tree.
 *
 * Return: Pointer to the node containing 'value', or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp = (bst_t *)tree;
	while (tmp && tmp->n != value)
		tmp = (tmp->n < value) ? tmp->right : tmp->left;
	return (tmp);
}
