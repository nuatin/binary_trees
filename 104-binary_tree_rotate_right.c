#include "binary_trees.h"

/**
 * binary_tree_rotate_right - RIGHT-ROTATES A BINARY TREE.
 * @tree: A POINTER TO THE ROOT NODE OF THE TREE TO ROTATE.
 *
 * Return: A POINTER TO THE NEW ROOT NODE AFTER ROTATION.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	binary_tree_t *pivot = tree->left;
	binary_tree_t *tmp = pivot->right;

	pivot->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;

	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;

	if (tmp != NULL)
		(tmp->left == tree) ? (tmp->left = pivot) : (tmp->right = pivot);

	return (pivot);
}
