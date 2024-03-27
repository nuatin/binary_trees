#include "binary_trees.h"

/**
 * FindLowestCommonAncestor - finds the lowest common ancestor of two nodes
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *FindLowestCommonAncestor(const binary_tree_t *node1,
		const binary_tree_t *node2)
{
	binary_tree_t *temp;

	if (node1 == NULL || node2 == NULL)
		return (NULL);

	temp = (binary_tree_t *)node2;

	while (node1)
	{
		while (node2)
		{
			if (node1 == node2)
				return ((binary_tree_t *)node1);
			node2 = node2->parent;
		}
		node2 = temp;
		node1 = node1->parent;
	}

	return (NULL);
}
