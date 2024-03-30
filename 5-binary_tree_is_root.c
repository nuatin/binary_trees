#include "binary_trees.h"

/**
 * check_if_root - checks if a given node is a root
 * @node: pointer to the node to be checked
 *
 * Return: 1 if node is a root, otherwise 0. If node is NULL, return 0
 */
int check_if_root(const binary_tree_t *node)
{
	if (node != NULL && node->parent == NULL)
		return (1);
	return (0);
}
