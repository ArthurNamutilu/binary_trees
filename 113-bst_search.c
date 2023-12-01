#include "binary_trees.h"
/**
 * bst_search - function search value in the tree and return the node
 * @tree: tree to traverse
 * @value: value to search
 * Return: node with value || NULL 
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *got;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		got = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		got = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (got);
}
