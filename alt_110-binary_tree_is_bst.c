#include "binary_trees.h"


/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid BST, and 0 if otherwise
 * also if tree is NULL, return 0;
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int check1, check2;

	if (tree == NULL)
		return (0);

	check1 = lefties(tree->left);
	check2 = righties(tree->right);
	return ((check1 && check2) ? 1 : 0);
}
