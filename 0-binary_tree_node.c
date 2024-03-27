#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a new binary tree node
 * @parent: pointer to the parent node of the new node
 * @value: value to be stored in the new node
 * Return: pointer to the newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));

	/* If memory allocation fails, return NULL */
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node with the provided values */
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;

	/* Return a pointer to the newly created node */
	return (new_node);
}
