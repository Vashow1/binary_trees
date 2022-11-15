#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 *
 * @tree: the pointer to the root of the tree
 * Return: the count or 0 if the tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;
	if (left == NULL && right == NULL)
		return (0);
	nodes += binary_tree_nodes(left) + binary_tree_nodes(right) + 1;
	return (nodes);
}
