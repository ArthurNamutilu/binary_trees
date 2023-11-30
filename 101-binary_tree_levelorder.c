#include "binary_trees.h"
/**
 * binary_tree_height - measures height of binary tree
 * @tree: tree to go through
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t m = 0;
	size_t n = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			m = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			n = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((m > n) ? m : n);
	}
}
/**
 * binary_tree_depth - specified node depth i.e from root
 * @tree: node being checked depth
 * Return: number of depth(0)
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - this function makes a linked list from depth level and node
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *n, *ax;

	n = malloc(sizeof(link_t));
	if (n == NULL)
	{
		return;
	}
	n->n = level;
	n->node = tree;
	if (*head == NULL)
	{
		n->next = NULL;
		*head = n;
	}
	else
	{
		ax = *head;
		while (ax->next != NULL)
		{
			ax = ax->next;
		}
		n->next = NULL;
		ax->next = n;
	}
}
/**
 * recursion - func goes through..
 * ..complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: nothing
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t l = 0;

	if (tree != NULL)
	{
		l = binary_tree_depth(tree);
		linked_node(head, tree, l);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - func that prints node elements in lever-order
 * @tree: root node
 * @func: function in use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *hd, *ax;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		hd = NULL;
		recursion(&hd, tree);
		while (count <= height)
		{
			ax = hd;
			while (ax != NULL)
			{
				if (count == ax->n)
				{
					func(ax->node->n);
				}
				ax = ax->next;
			}
			count++;
		}
		while (hd != NULL)
		{
			ax = hd;
			hd = hd->next;
			free(ax);
		}
	}
}
