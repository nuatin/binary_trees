#include "binary_trees.h"

/**
 * traverse_binary_tree_preorder - traverses a binary tree using pre-order method
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to the function to call for each node
 *         The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void traverse_binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	traverse_binary_tree_preorder(tree->left, func);
	traverse_binary_tree_preorder(tree->right, func);
}
