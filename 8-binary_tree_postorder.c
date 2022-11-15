#include "binary_trees.h"

/**
 * binary_tree_postorder - function that goes through a
 * binary tree using post-order traversal
 *
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *right, *left;
	int value;

	if (tree == NULL || func == NULL)
		return;

	right = tree->right;
	left = tree->left;
	value = tree->n;
	binary_tree_postorder(left, func);
	binary_tree_postorder(right, func);
	func(value);
}
