#include "binary_trees.h"

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return 1;
	return 0;
}

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return 0;
	if (binary_tree_is_leaf(tree))
		return 1;
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	return left + right;
}
