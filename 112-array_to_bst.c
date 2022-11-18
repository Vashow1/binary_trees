#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 *
 * @array: pointer to the first elemet of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL
 * on failure;
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	for (size_t i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
