#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotat
 * Return: pointer to the new root
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	root = tree->left;
	tree->left = root->right;

	if (root->right)
	{
		root->right->parent = tree;
	}

	root->parent = tree;
	if (tree->parent)
	{
		if (tree->parent->right == tree)
		{
			tree->parent->right = root;
		} else if (tree->parent->left == tree)
		{
			tree->parent->left = root;
		}
	}
	tree->parent = root;
	root->right = tree;
	return (root);
}
