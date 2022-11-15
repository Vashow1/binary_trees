#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: the ponter to the root node of the tree
 * Return: the number of leaves or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;


	if (left == NULL && right == NULL)
		return (1);

	leaves += binary_tree_leaves(left) + binary_tree_leaves(right);
	return (leaves);
}
