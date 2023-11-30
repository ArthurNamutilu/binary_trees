#include "binary_trees.h"
/**
 * binary_tree_depth - node's depth (specified from root)
 * @tree: node to check its depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
