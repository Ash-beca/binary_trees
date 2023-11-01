#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((lef > rig) ? lef : rig);
	}

	return (0);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: return 0, if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);
	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}
