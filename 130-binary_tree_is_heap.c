#include "binary_trees.h"

/**
 * calculate_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t calculate_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (calculate_tree_size(tree->left) + calculate_tree_size(tree->right) + 1);
}

/**
 * check_if_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root of the tree.
 * @index: Current index of the node.
 * @total_nodes: Total number of nodes in the tree.
 * Return: 1 if tree is complete, 0 otherwise.
 */
int check_if_complete(const binary_tree_t *tree, int index, int total_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= total_nodes)
		return (0);

	return (check_if_complete(tree->left, (2 * index) + 1, total_nodes) &&
		check_if_complete(tree->right, (2 * index) + 2, total_nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root of the tree.
 * Return: 1 if tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t total_nodes;

	if (tree == NULL)
		return (0);

	total_nodes = calculate_tree_size(tree);

	return (check_if_complete(tree, 0, total_nodes));
}

/**
 * check_parent_value - Checks if parent has a greater value than its children.
 *
 * @tree: Pointer to the node.
 * Return: 1 if parent has a greater value, 0 otherwise.
 */
int check_parent_value(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent_value(tree->left) && check_parent_value(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a Max Binary Heap.
 *
 * @tree: Pointer to the root of the tree.
 * Return: 1 if tree is a Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent_value(tree->left) && check_parent_value(tree->right));
}

