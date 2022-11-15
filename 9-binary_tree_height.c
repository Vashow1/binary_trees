#include "binary_trees.h"

/**
 * MAX - compares two unsigned integers and returns the bigger
 *
 * @a: first size_t value
 * @b: second size_t value
 * Return: the bigger size_t
 */

size_t MAX(size_t a, size_t b)
{
	return ((a >= b) ? a : b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: the height and if tree is NULL return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *right, *left;
	size_t leftHeight = 0, rightHeight = 0;

	if (tree == NULL)
		return (0);

	right = tree->right;
	left = tree->left;

	leftHeight = (left == NULL) ? 0 : (binary_tree_height(left) + 1);
	rightHeight = (right == NULL) ? 0 : (binary_tree_height(right) + 1);
	return (MAX(leftHeight, rightHeight));
}
