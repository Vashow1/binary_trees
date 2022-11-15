#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child
 * of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *child = malloc(sizeof(binary_tree_t));

	if (child == NULL)
		return (NULL);

	if (parent == NULL)
	{
		free(child);
		return (NULL);
	}

	child->n = value;
	child->parent = parent;
	child->right = NULL;
	if (parent->left == NULL)
	{
		parent->left = child;
		child->left = NULL;
	} else
	{
		child->left = parent->left;
		parent->left->parent = child;
		parent->left = child;
	}

	return (child);
}
