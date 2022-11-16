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
	binary_tree_t *firstPa, *secondPa, *temp;
	binary_tree_t **ancestors;
	int size;

	if (first == NULL || second == NULL)
		return (NULL);

	temp = (binary_tree_t *) first;

	for (size = 1; temp; size++)
		temp = temp->parent;
	ancestors = malloc(sizeof(int) * size);
	firstPa = first->parent;
	secondPa = second->parent;

	if (first == second)
		return ((binary_tree_t *) first);
	if (first == secondPa)
		return ((binary_tree_t *) first);
	if (second == firstPa)
		return ((binary_tree_t *) second);

	for (int i = 0; firstPa; i++)
	{
		ancestors[i] = (binary_tree_t *)firstPa;
		firstPa = firstPa->parent;
	}
	for (int i = 0; ancestors[i]; i++)
	{
		while (secondPa)
		{
			if (secondPa == ancestors[i])
				return (secondPa);
			secondPa = secondPa->parent;
		}
	}
	return (NULL);
}
