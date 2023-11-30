#include "binary_trees.h"
/**
 * binary_tree_preorder - func that prints elements of tree..
 * ..using pre-order traversal
 * @tree: tree to go through
 * @func: func to use
 * Return: 0
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
    {
        return;
    }
    else
    {
        func(tree->n);
        binary_tree_preorder(tree->left, func);
        binary_tree_preorder(tree->right, func);
    }
}
