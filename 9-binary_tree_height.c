#include "binary_trees.h"

/**
 * check_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int check_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * measure_binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t measure_binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || check_leaf(tree))
		return (0);
	left = measure_binary_tree_height(tree->left);
	right = measure_binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}
