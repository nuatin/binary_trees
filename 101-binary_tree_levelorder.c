#include "binary_trees.h"

/**
 * FindTreeHeight - calculates the height of a binary tree
 * @root: pointer to the root node of the tree
 * Return: height of the tree. If the tree is empty, return 0
 */
size_t FindTreeHeight(const binary_tree_t *root)
{
	size_t left_height, right_height;

	if (root == NULL)
		return (0);

	left_height = FindTreeHeight(root->left);
	right_height = FindTreeHeight(root->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * TraverseLevel - performs a function on a specific level of a binary tree
 * @node: pointer to the current node being processed
 * @level: level of the tree to perform the function on
 * @func: pointer to the function to call for each node
 * Return: void
 */
void TraverseLevel(const binary_tree_t *node, size_t level, void (*func)(int))
{
	if (node == NULL)
		return;

	if (level == 1)
		func(node->n);
	else if (level > 1)
	{
		TraverseLevel(node->left, level - 1, func);
		TraverseLevel(node->right, level - 1, func);
	}
}

/**
 * PerformLevelOrderTraversal - traverses a binary tree using level-order traversal
 * @root: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 * Return: void
 */
void PerformLevelOrderTraversal(const binary_tree_t *root, void (*func)(int))
{
	size_t tree_height, level;

	if (root == NULL || func == NULL)
		return;

	tree_height = FindTreeHeight(root);

	for (level = 1; level <= tree_height; level++)
		TraverseLevel(root, level, func);
}
