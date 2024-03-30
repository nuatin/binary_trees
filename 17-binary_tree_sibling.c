#include "binary_trees.h"

/**
 * find_sibling - Find the sibling of a node
 * @node: A pointer to the node to find the sibling of
 *
 * Return: A pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *find_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
