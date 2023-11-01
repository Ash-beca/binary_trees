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
 * binary_tree_balance - function that measures the balance
 * factor of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: return 0, if tre is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int lef = 0, rig = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lef = (int)binary_tree_height(tree->left);
	else
		lef = -1;

	if (tree->right)
		rig = (int)binary_tree_height(tree->right);
	else
		rig = -1;

	return (lef - rig);

}
