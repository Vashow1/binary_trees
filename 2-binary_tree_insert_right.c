#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the left-child
 * of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *child = malloc(sizeof(binary_tree_t));

	if (child == NULL)
		return (NULL);

	child->n = value;
	child->parent = parent;
	child->left = NULL;
	if (parent->right == NULL)
	{
		parent->right = child;
		child->right = NULL;
	} else
	{
		child->right = parent->right;
		parent->right->parent = child;
		parent->right = child;
	}

	return (child);
}
