#include "binary_trees.h"

/**
 * binary_tree_inorder - function that goes through a
 * binary tree using in-order traversal
 *
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *right, *left;
	int value;

	if (tree == NULL || func == NULL)
		return;

	right = tree->right;
	left = tree->left;
	value = tree->n;
	binary_tree_inorder(left, func);
	func(value);
	binary_tree_inorder(right, func);
}
