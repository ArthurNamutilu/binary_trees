#include "binary_trees.h"

/**
 * binary_tree_is_perfect - func checks if a binary tree is perfect
 * @tree: ptr to the root node 
 * ..of the tree to check
 *
 * Return: 1 -> tree is perfect || 0 -> tree not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t ht = 0;
	size_t nds = 0;
	size_t pwr = 0;

	if (!tree)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	ht = binary_tree_height(tree);
	nds = binary_tree_size(tree);

	pwr = (size_t)_pow_recursion(2, ht + 1);
	return (pwr - 1 == nds);
}

/**
 *_pow_recursion - returns the value of x raised to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));

}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
