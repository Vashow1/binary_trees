#include "binary_trees.h"

/**
 * tree_insert_rec - performs insertion recursively
 *
 * @temp: points to a ever changing initial root of tree
 * @looping: precursor to temp
 * @inserted: the struct to be inserted
 * Return: the node of the inserted node;
 */

bst_t *tree_insert_rec(bst_t *temp, bst_t *looping, bst_t *inserted)
{
	if (looping != NULL)
	{
		if (inserted->n < looping->n)
		{
			tree_insert_rec(looping, looping->left, inserted);
			return (inserted);
		}
		else if (inserted->n > looping->n)
		{
			tree_insert_rec(looping, looping->right, inserted);
			return (inserted);
		}
		else if (inserted->n == looping->n)
			return (NULL);
	}

	inserted->parent = temp;
	if (inserted->n < temp->n)
		temp->left = inserted;
	else
		temp->right = inserted;
	return (inserted);
}

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
	bst_t *inserted;

	inserted = binary_tree_node(NULL, value);

	if (*tree == NULL)
		return (*tree = inserted);

	inserted = (tree_insert_rec(temp, looping, inserted));
	if (inserted->parent == NULL)
		return (NULL);
	return (inserted);
}

