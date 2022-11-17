#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree
 *
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: pointer to the created node or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *looping = *tree;
	bst_t *inserted = malloc(sizeof(bst_t));

	if (inserted == NULL)
		return (NULL);

	inserted->n = value;
	while (looping != NULL)
	{
		temp = looping;
		if (value < looping->n)
			looping = looping->left;
		else if (value > looping->n)
			looping = looping->right;
		else
			return (NULL);
	}

	inserted->parent = temp;
	if (temp == NULL)
		*tree = inserted;
	else if (value < temp->n)
		temp->left = inserted;
	else
		temp->right = inserted;

	return (inserted);
}
