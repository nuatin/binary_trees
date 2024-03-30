#include "binary_trees.h"
#include "limits.h"

/**
 * find_height - Measures the height of a binary tree.
 * @node: A pointer to the root node of the tree to measure the height.
 *
 * Return: If node is NULL, the function returns 0; otherwise, it returns the height.
 */
size_t find_height(const binary_tree_t *node)
{
	if (node)
	{
		size_t left_height = 0, right_height = 0;

		left_height = node->left ? 1 + find_height(node->left) : 1;
		right_height = node->right ? 1 + find_height(node->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * check_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @node: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited thus far.
 * @max: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, it returns 1; otherwise, it returns 0.
 */
int check_avl_helper(const binary_tree_t *node, int min, int max)
{
	size_t left_height, right_height, height_diff;

	if (node != NULL)
	{
		if (node->n < min || node->n > max)
			return (0);
		left_height = find_height(node->left);
		right_height = find_height(node->right);
		height_diff = left_height > right_height ? left_height - right_height : right_height - left_height;
		if (height_diff > 1)
			return (0);
		return (check_avl_helper(node->left, min, node->n - 1) &&
				check_avl_helper(node->right, node->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is a valid AVL tree, it returns 1; otherwise, it returns 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_avl_helper(tree, INT_MIN, INT_MAX));
}
