#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: is the pointer to the first node
 * @second: is the pointer to the second node
 * Return: return a pointer to the lowest common ancestor node
 * of the two given nodes
 * if no common ancestor is found, return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *firstPa, *secondPa;

	if (first == NULL || second == NULL)
		return (NULL);

	firstPa = first->parent;
	secondPa = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);

	if (first == secondPa || firstPa == NULL)
		return (binary_trees_ancestor(first, secondPa));
	else if (second == firstPa || secondPa == NULL)
		return (binary_trees_ancestor(firstPa, second));
	else
		return (binary_trees_ancestor(firstPa, secondPa));

}
