#include "binary_trees.h"

/**
 * binary_tree_height - measures height of binary tree
 * @tree: tree to traverse
 * Return:  height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t m = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			m = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((m > r) ? m : r);
	}
}
