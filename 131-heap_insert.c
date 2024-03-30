#include "binary_trees.h"

#define INITIAL_NODE {0, NULL, NULL, NULL}

/**
 * swap_nodes - Swaps two nodes in a binary tree.
 * @a: First node to swap.
 * @b: Second node to swap.
 * Return: Pointer to the root node.
 */
bst_t *swap_nodes(bst_t *a, bst_t *b)
{
	bst_t a_copy = INITIAL_NODE;

	a_copy.n = a->n;
	a_copy.parent = a->parent;
	a_copy.left = a->left;
	a_copy.right = a->right;

	a->parent = b;
	a->left = b->left;
	a->right = b->right;

	if (b->left)
		b->left->parent = a;
	if (b->right)
		b->right->parent = a;

	b->parent = a_copy.parent;

	if (a_copy.parent)
	{
		if (a == a_copy.parent->left)
			a_copy.parent->left = b;
		else
			a_copy.parent->right = b;
	}

	if (b == a_copy.left)
	{
		b->left = a;
		b->right = a_copy.right;

		if (a_copy.right)
			a_copy.right->parent = b;
	}
	else if (b == a_copy.right)
	{
		b->right = a;
		b->left = a_copy.left;

		if (a_copy.left)
			a_copy.left->parent = b;
	}

	while (b->parent)
		b = b->parent;

	return (b);
}

/**
 * convert_to_base - Converts a number into a string representation of a given base.
 * @num: Input number.
 * @base: Base to convert to.
 * @lowercase: Flag indicating whether hexa values need to be lowercase.
 * Return: Result string.
 */
char *convert_to_base(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";

	ptr = &buffer[49];
	*ptr = 0;

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
}

/**
 * tree_size - Measures the size of a binary tree.
 * @tree: Input binary tree.
 * Return: Number of descendant child nodes.
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * insert_node - Helper function to insert a node at the correct location.
 * @root: Double pointer to root of the max heap.
 * @node: Node to insert.
 */
void insert_node(heap_t **root, heap_t *node)
{
	heap_t *tmp;
	int size;
	unsigned int i;
	char *binary;
	char c;

	tmp = *root;
	size = tree_size(tmp) + 1;
	binary = convert_to_base(size, 2, 1);

	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];

		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				node->parent = tmp;
				tmp->right = node;
				break;
			}
			else if (c == '0')
			{
				node->parent = tmp;
				tmp->left = node;
				break;
			}
		}

		if (c == '1')
			tmp = tmp->right;
		else if (c == '0')
			tmp = tmp->left;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to root of the tree.
 * @value: Input value.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *ht = NULL, *ret;

	if (!root)
		return (NULL);

	ht = calloc(1, sizeof(heap_t));
	ht->n = value;

	if (!*root)
	{
		*root = ht;
		return (ht);
	}

	insert_node(root, ht);

	while (ht->parent && ht->n > ht->parent->n)
	{
		ret = swap_nodes(ht->parent, ht);
		if (ret)
			*root = ret;
	}

	return (ht);
}
