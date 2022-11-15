#include "binary_trees.h"
/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * @tree: a pointer to the root node of the tree to delete
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *nleft, *nright;

	if (tree == NULL)
		return;

	nleft = tree->left;
	nright = tree->right;

	binary_tree_delete(nleft);
	binary_tree_delete(nright);

	free(tree);
}
