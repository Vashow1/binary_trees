#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: the pointer to the node
 * Return: pointer to the sibling node or
 * if node is NULL or if the parent is NULL return NULL
 * if node has no sibling, return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *papa, *paLeft, *paRight;

	if (node == NULL)
		return (NULL);
	papa = node->parent;

	if (papa == NULL)
		return (NULL);

	paLeft = papa->left;
	paRight = papa->right;

	return ((paLeft == node) ? paRight : paLeft);
}
