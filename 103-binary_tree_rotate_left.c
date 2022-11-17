#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 *
 * @tree: the pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	root = tree->right;
	tree->right = root->left;

	if (root->left)
	{
		root->left->parent = tree;
	}

	root->parent = tree->parent;

	if (tree->parent)
	{
		if (tree == tree->parent->left)
		{
			tree->parent->left = root;
		} else if (tree == tree->parent->right)
		{
			tree->parent->right = root;
		}
	}

	root->left = tree;
	tree->parent = root;
	return (root);
}
