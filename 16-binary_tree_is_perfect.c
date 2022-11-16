#include "binary_trees.h"
#include "stdbool.h"

/**
 * tree_height - measures the height of a binary tree
 *
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: the height and if tree is NULL return 0
 */

int tree_height(const binary_tree_t *tree)
{
	binary_tree_t *right, *left;
	int leftHeight = 0, rightHeight = 0;

	if (tree == NULL)
		return (-1);

	right = tree->right;
	left = tree->left;

	leftHeight = (left == NULL) ? 0 : (tree_height(left) + 1);
	rightHeight = (right == NULL) ? 0 : (tree_height(right) + 1);
	return ((leftHeight >= rightHeight) ? leftHeight : rightHeight);
}

/**
 * tree_balance - measures the balance factor of a binary tree
 *
 * @tree: the pointer to the root of the tree
 * Return: the factor
 */

int tree_balance(const binary_tree_t *tree)
{
	int factor = 0;
	size_t leftH, rightH;

	if (tree == NULL)
		return (0);

	leftH = tree_height(tree->left);
	rightH = tree_height(tree->right);
	factor = leftH - rightH;
	return (factor);
}

/**
 * tree_is_full - checks if binary tree is full
 *
 * @tree: pointer to the root node of tree
 * Return: 1 if full and 0 otherwise
 */

int tree_is_full(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (left == NULL && right == NULL)
		return (1);

	if (left && right)
		return ((tree_is_full(left) &&
			tree_is_full(right)) ? 1 : 0);


	return (0);
}


/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 *
 * @tree: pointer to the root node of tree
 * Return: 1 if perfect and 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	bool check1, check2;

	if (tree == NULL)
		return (0);

	check1 = (tree_balance(tree) == 0) ? true : false;
	check2 = (tree_is_full(tree) == 0) ? false : true;

	return ((check1 && check2)
		? 1 : 0);
}
