#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if binary tree is full
 *
 * @tree: pointer to the root node of tree
 * Return: 1 if full and 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (left == NULL && right == NULL)
		return (1);

	if (left && right)
		return ((binary_tree_is_full(left) &&
				binary_tree_is_full(right)) ? 1 : 0);


	return (0);
}
