#include "binary_trees.h"
/**
 * check_sub_tree_Left - function check if all nodes are..
 * .. smaller than the root specified
 * @node: node
 * @max: value to compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int l = 0, r = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		l = check_sub_tree_Left(node->l, max);
		r = check_sub_tree_Left(node->r, max);
		if (l == r && l == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - func checks if all the nodes are bigger than the
 * root specified
 * @node: node in the tree to verify condition
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int l = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		l = check_sub_tree_Right(node->l, min);
		right = check_sub_tree_Right(node->right, min);
		if (l == right && l == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - func says if a tree is a bst or not
 * the process here is first verify..
 * that the l node be smaller than the root then verify if the right node is bigger 
 * than th root after that verify if the l subtree has nodes smaller than root
 * and the right subtree has bigger nodes than root
 * @tree: node that point to the tree to check
 * Return: 1 if it is a BST || 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int varia = 0, l = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->l && tree->l->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->l && tree->l->n < tree->n)
	{
		var = check_sub_tree_Left(tree->l, tree->n);
		if (var == 0)
			return (0);
		l = binary_tree_is_bst(tree->l);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (l != 2 || right != 2)
	{
		if (l == 0 || right == 0)
			return (0);
	}
	return (1);
}
