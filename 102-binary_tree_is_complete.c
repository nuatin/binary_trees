#include "binary_trees.h"
#include <stdio.h>

/**
 * IsLeaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int IsLeaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * MeasureTreeHeight - measures the height of a binary tree
 * @root: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t MeasureTreeHeight(const binary_tree_t *root)
{
	size_t left_height, right_height;

	if (root == NULL)
		return (0);
	left_height = MeasureTreeHeight(root->left);
	right_height = MeasureTreeHeight(root->right);
	if (left_height >= right_height)
		return (1 + left_height);
	return (1 + right_height);
}

/**
 * IsPerfect - checks if a binary tree is perfect
 * @root: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int IsPerfect(const binary_tree_t *root)
{
	binary_tree_t *left, *right;

	if (root == NULL)
		return (1);
	left = root->left;
	right = root->right;
	if (IsLeaf(root))
		return (1);
	if (left == NULL || right == NULL)
		return (0);
	if (MeasureTreeHeight(left) == MeasureTreeHeight(right))
	{
		if (IsPerfect(left) && IsPerfect(right))
			return (1);
	}
	return (0);
}

/**
 * IsComplete -  checks if a binary tree is complete
 * @root: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int IsComplete(const binary_tree_t *root)
{
	size_t left_height, right_height;
	binary_tree_t *left, *right;

	if (root == NULL)
		return (0);
	if (IsLeaf(root))
		return (1);
	left = root->left;
	right = root->right;
	left_height = MeasureTreeHeight(left);
	right_height = MeasureTreeHeight(right);
	if (left_height == right_height)
	{
		if (IsPerfect(left) && IsComplete(right))
			return (1);
	}
	else if (left_height == right_height + 1)
	{
		if (IsComplete(left) && IsPerfect(right))
			return (1);
	}
	return (0);
}
