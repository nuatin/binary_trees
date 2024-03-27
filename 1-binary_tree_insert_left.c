#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a new node as the left child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Description: If the parent already has a left child, the new node will take its
 * place, and the old left child will be set as the left child of the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left;

	if (parent == NULL)
		return (NULL);

	new_left = binary_tree_node(parent, value);
	if (new_left == NULL)
		return (NULL);

	new_left->left = parent->left;
	if (new_left->left != NULL)
		new_left->left->parent = new_left;

	parent->left = new_left;

	return (new_left);
}
