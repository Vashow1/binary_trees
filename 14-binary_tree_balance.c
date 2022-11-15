#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 *
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: the height and if tree is NULL return 0
 */

size_t tree_height(const binary_tree_t *tree)
{
	binary_tree_t *right, *left;
	size_t leftHeight = 0, rightHeight = 0;

	if (tree == NULL)
		return (-1);

	right = tree->right;
	left = tree->left;

	leftHeight = (left == NULL) ? 0 : (tree_height(left) + 1);
	rightHeight = (right == NULL) ? 0 : (tree_height(right) + 1);
	return ((leftHeight >= rightHeight) ? leftHeight : rightHeight);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: the pointer to the root of the tree
 * Return: the factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int factor = 0;
	binary_tree_t *left, *right;
	size_t leftH, rightH;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;
	leftH = tree_height(left);
	rightH = tree_height(right);
	factor = leftH - rightH;
	return (factor);
}
