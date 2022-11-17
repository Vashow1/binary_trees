#include "binary_trees.h"

/**
 * minimum - finds the minimum value in a subtree
 *
 * @tree: pointer to the root of the tree
 * Return: the minimum value or the max if root is null
 */

int minimum(binary_tree_t *tree)
{
	int value, leftMin, rightMin, minimumLefRig;

	if (tree == NULL)
		return (INT_MAX);

	value = tree->n;
	leftMin = minimum(tree->left);
	rightMin = minimum(tree->right);

	minimumLefRig = ((leftMin < rightMin) ? leftMin : rightMin);
	return ((value < minimumLefRig) ? value : minimumLefRig);
}

/**
 * maximum - finds the maximum value in a subtree
 *
 * @tree: pointer to the root of the tree
 * Return: the maximum value or the min if the root is NULL
 */
int maximum(binary_tree_t *tree)
{
	int value, leftMax, rightMax, maximumLefRig;

	if (tree == NULL)
		return (INT_MIN);

	value = tree->n;
	leftMax = maximum(tree->left);
	rightMax = maximum(tree->right);
	maximumLefRig = ((leftMax < rightMax) ? leftMax : rightMax);
	return ((value < maximumLefRig) ? value : maximumLefRig);
}

/**
 * binary_tree_is_bst - checks if a binary tree is valid
 *
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is valid BST and 0 if otherwise
 * if tree is NULL also return 0;
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left != NULL)
		&& (maximum(tree->left) > tree->n))
		return (0);

	if ((tree->right != NULL)
		&& (minimum(tree->right) < tree->n))
		return (0);

	if (!binary_tree_is_bst(tree->left)
		|| !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}
