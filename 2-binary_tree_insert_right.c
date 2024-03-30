#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right child of another node
 * @parent: Pointer to the node to insert the right child in
 * @value: Value to store in the new node
 *
 * Description: This function inserts a new node as the right child of the
 * provided parent node. If the parent already has a right child, the new node
 * takes its place, and the old right child becomes the right child of the new
 * node.
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);

	right_child = binary_tree_node(parent, value);
	if (right_child == NULL)
		return (NULL);

	right_child->right = parent->right;
	if (right_child->right != NULL)
		right_child->right->parent = right_child;

	parent->right = right_child;

	return (right_child);
}
