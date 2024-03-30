#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tree - Stores recursively each level in an array of strings
 *
 * @node: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @buffer: Buffer
 *
 * Return: Length of printed tree after process
 */
static int print_tree(const binary_tree_t *node, int offset, int depth, char **buffer)
{
	char node_val[6];
	int width, left, right, is_left, i;

	if (!node)
		return (0);

	is_left = (node->parent && node->parent->left == node);
	width = sprintf(node_val, "(%03d)", node->n);
	left = print_tree(node->left, offset, depth + 1, buffer);
	right = print_tree(node->right, offset + left + width, depth + 1, buffer);

	for (i = 0; i < width; i++)
		buffer[depth][offset + left + i] = node_val[i];

	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			buffer[depth - 1][offset + left + width / 2 + i] = '-';
		buffer[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			buffer[depth - 1][offset - width / 2 + i] = '-';
		buffer[depth - 1][offset + left + width / 2] = '.';
	}

	return (left + width + right);
}

/**
 * get_height - Measures the height of a binary tree
 *
 * @node: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t get_height(const binary_tree_t *node)
{
	size_t height_left, height_right;

	height_left = node->left ? 1 + get_height(node->left) : 0;
	height_right = node->right ? 1 + get_height(node->right) : 0;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **buffer;
	size_t height, i, j;

	if (!tree)
		return;

	height = get_height(tree);
	buffer = malloc(sizeof(*buffer) * (height + 1));

	if (!buffer)
		return;

	for (i = 0; i < height + 1; i++)
	{
		buffer[i] = malloc(sizeof(**buffer) * 255);

		if (!buffer[i])
			return;

		memset(buffer[i], 32, 255);
	}

	print_tree(tree, 0, 0, buffer);

	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (buffer[i][j] != ' ')
				break;
			buffer[i][j] = '\0';
		}
		printf("%s\n", buffer[i]);
		free(buffer[i]);
	}
	free(buffer);
}
