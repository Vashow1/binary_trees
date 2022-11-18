#include "binary_trees.h"

/**
 * transplant - replaces on subtree as a child of its parent
 * with another subtree
 *
 * @going: being replaced
 * @replacement: replacing going
 * Return: root
 */

bst_t *transplant(bst_t *root, *going, *replacement)
{
	if (going->parent == NULL)
		root = replacement;
	else if (going == going->parent->left)
		going->parent->left = replacement;
	else
		going->parent->right = replacement;

	if (replacement != NULL)
		replacement->parent = going->parent;
}


/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removal
 */


