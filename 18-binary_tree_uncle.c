#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: is a pointer to the node to find the uncle
 * Return: the pointer to the uncle node and
 * if node is NULL, return NULL
 * if node has no uncle, return NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *papa, *grandpa;

	if (node == NULL)
		return (NULL);

	papa = node->parent;

	if (papa == NULL)
		return (NULL);

	grandpa = papa->parent;

	if (grandpa == NULL)
		return (NULL);

	return ((grandpa->left == papa) ? grandpa->right : grandpa->left);
}
