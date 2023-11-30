#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary node
 * @parent: node parent
 * @val: Value of the node
 * Return: the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int val)
{
	binary_tree_t *newNde;

	newNde = malloc(sizeof(binary_tree_t));
	if (newNde == NULL)
	{
		return (NULL);
	}
	newNde->n = val;
	newNde->parent = parent;
	newNde->left = NULL;
	newNde->right = NULL;
	return (newNde);
}
