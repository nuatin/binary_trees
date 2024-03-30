#include "binary_trees.h"

/**
 * is_leaf_node - Checks if a node is a leaf.
 * @node: Pointer to the node to check.
 *
 * Returns: 1 if the node is a leaf, 0 otherwise. If node is NULL, returns 0.
 */
int is_leaf_node(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * count_internal_nodes - Counts the internal nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Description: A NULL pointer is not considered a node.
 *
 * Returns: The number of internal nodes in the binary tree.
 */
size_t count_internal_nodes(const binary_tree_t *tree)
{
	size_t left_count, right_count;

	if (tree == NULL || is_leaf_node(tree))
		return (0);

	left_count = count_internal_nodes(tree->left);
	right_count = count_internal_nodes(tree->right);

	return (1 + left_count + right_count);
}
