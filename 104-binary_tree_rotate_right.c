#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates right the binary tree.
 * @tree: Tree root node
 * Return: new node ptr
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvt;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pvt = tree->left;
	tree->left = pvt->right;
	if (pvt->right != NULL)
	{
		pvt->right->parent = tree;
	}
	pvt->right = tree;
	pvt->parent = tree->parent;
	tree->parent = pvt;
	return (pvt);
}
