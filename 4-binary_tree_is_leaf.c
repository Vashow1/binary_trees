#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 * and also 0 if node is NULL
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	binary_tree_t *left, *right;

	if (node == NULL)
		return (0);

	left = node->left;
	right = node->right;

	return ((left == NULL && right == NULL) ? 1 : 0);
}
