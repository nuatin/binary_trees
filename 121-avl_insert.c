#include "binary_trees.h"

/**
 * calculate_height - Calculates the height of a binary tree.
 * @node: A pointer to the node of the tree.
 *
 * Return: The height of the tree.
 */
size_t calculate_height(const binary_tree_t *node)
{
	if (node != NULL)
	{
		size_t left_height = 0, right_height = 0;

		left_height = node->left ? 1 + calculate_height(node->left) : 1;
		right_height = node->right ? 1 + calculate_height(node->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * calculate_balance - Calculates the balance factor of a binary tree.
 * @node: A pointer to the node of the tree.
 *
 * Return: The balance factor of the tree.
 */
int calculate_balance(const binary_tree_t *node)
{
	return (node != NULL ? calculate_height(node->left) - calculate_height(node->right) : 0);
}

/**
 * avl_insert_recursive_custom - Inserts a value into an AVL tree recursively.
 * @root: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive_custom(avl_t **root, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (*root == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*root)->n > value)
	{
		(*root)->left = avl_insert_recursive_custom(&(*root)->left, *root, new_node, value);
		if ((*root)->left == NULL)
			return (NULL);
	}
	else if ((*root)->n < value)
	{
		(*root)->right = avl_insert_recursive_custom(&(*root)->right, *root, new_node, value);
		if ((*root)->right == NULL)
			return (NULL);
	}
	else
		return (*root);

	balance_factor = calculate_balance(*root);
	if (balance_factor > 1 && (*root)->left->n > value)
		*root = binary_tree_rotate_right(*root);
	else if (balance_factor < -1 && (*root)->right->n < value)
		*root = binary_tree_rotate_left(*root);
	else if (balance_factor > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}

	return (*root);
}

/**
 * avl_insert_custom - Inserts a value into an AVL tree.
 * @root: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert_custom(avl_t **root, int value)
{
	avl_t *new_node = NULL;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	avl_insert_recursive_custom(root, *root, &new_node, value);
	return (new_node);
}
