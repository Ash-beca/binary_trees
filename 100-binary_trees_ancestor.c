#include "binary_trees.h"
/**
 * binary_trees_ancestor - a function that finds the lowest
 * common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: pointer to the sibling node or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);
	if (first == second->parent)
		return ((binary_tree_t *)second);

	while (first != NULL)
	{
		parent = (binary_tree_t *)second;
		while (parent != NULL)
		{
			if (parent == first)
				return (parent);
			parent = parent->parent;
		}
		first = first->parent;
	}
	return (NULL);

}
