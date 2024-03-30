#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, 0 otherwise. If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);

	return (0);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, otherwise 0. If tree is NULL, return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (!tree)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);

	if (!left_full || !right_full)
		return (0);

	return (1);
}
