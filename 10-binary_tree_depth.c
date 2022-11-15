#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 *
 * @tree: pointer to the node to measure the depth
 * Return: the level or 0 if the tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *papa;
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	papa = tree->parent;

	if (papa == NULL)
		return (0);

	depth = (binary_tree_depth(papa) + 1);

	return (depth);
}
