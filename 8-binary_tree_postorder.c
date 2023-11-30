#include "binary_trees.h"
/**
 * binary_tree_postorder - func that print elements of tree..
 * ..using post-order traversal
 * @tree: tree to be traversed
 * @func: actve func
 * Return: 0
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
