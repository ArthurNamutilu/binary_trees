#include "binary_trees.h"

/**
 * binary_tree_nodes - function that Counts the nodes with at leastn..
 * ..1 child in binary tree
 * @tree: Ptr to root node to count number of nodes
 *
 * Return: No of nodes || 0 if tree is NULL or pointer isn't node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
