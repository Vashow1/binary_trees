#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: the pointer to the root node of the tree
 * Return: the size and 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t size = 0;

	if (tree == NULL)
		return (0);
	left = tree->left;
	right = tree->right;

	size = binary_tree_size(left) + binary_tree_size(right) + 1;


	return (size);
}
