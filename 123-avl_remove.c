#include "binary_trees.h"

/**
 * check_balance - Checks and corrects the balance factor of an AVL tree.
 * @tree: The root of the AVL tree to be checked.
 */
void check_balance(avl_t **tree)
{
	int balance_value;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	check_balance(&(*tree)->left);
	check_balance(&(*tree)->right);

	balance_value = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the successor (minimum value) in a BST.
 * @node: The node to start searching from.
 * Return: The minimum value in the subtree rooted at @node.
 */
int find_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);
	else
	{
		left = find_successor(node->left);
		if (left == 0)
			return (node->n);
		return (left);
	}
}

/**
 * remove_node_type - Removes a node from a BST based on its children.
 * @root: The node to be removed.
 * Return: 0 if the node has no children, otherwise the value of the successor.
 */
int remove_node_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = find_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_delete - Deletes a node from a BST.
 * @root: The root of the BST.
 * @value: The value to be deleted.
 * Return: The updated root of the BST.
 */
bst_t *bst_delete(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_delete(root->left, value);
	else if (value > root->n)
		bst_delete(root->right, value);
	else if (value == root->n)
	{
		type = remove_node_type(root);
		if (type != 0)
			bst_delete(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_delete - Deletes a node from an AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value to be deleted.
 * Return: The updated root of the AVL tree.
 */
avl_t *avl_delete(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_delete((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);

	check_balance(&root_a);
	return (root_a);
}
