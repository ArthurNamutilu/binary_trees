#include "binary_trees.h"
/**
 * bst_insert - func that inserts nodes in order to create a BST tree
 * @tree: tree to create
 * @value: node value to insert
 * Return: bst tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nw, *tmp;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		nw = (bst_t *)aux;
		*tree = nw;
	}
	else
	{
		tmp = *tree;
		if (value < tmp->n)
		{
			if (tmp->left)
				nw = bst_insert(&tmp->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)tmp, value);
				nw = tmp->left = (bst_t *)aux;
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				nw = bst_insert(&tmp->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)tmp, value);
				nw = tmp->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (nw);
}
