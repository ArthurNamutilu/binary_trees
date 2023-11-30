#include "binary_trees.h"

/**
 * binary_tree_height - Func that measures the height of a binary tree
 * @tree: root node ptr
 *
 * Return: tree height || -1 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ht_l;
	size_t ht_r;

	if (!tree)
		return (0);

	ht_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	ht_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (ht_l > ht_r ? ht_l : ht_r);
}

/**
 * binary_tree_balance - func gets balance factor of binary tree
 * @tree: Ptr to root of binary tree
 *
 * Return: Balance factor of binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int ht_l;
	int ht_r;

	if (!tree)
		return (0);

	ht_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	ht_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (ht_l - ht_r);
}
