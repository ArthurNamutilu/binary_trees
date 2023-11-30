#include "binary_trees.h"
/**
 * binary_tree_inorder - func that prints elements of tree
 * ..using in-order traversal
 * @tree: The tree
 * @func: actve func
 * Return: 0
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
    {
        return;
    }
    else
    {
        binary_tree_inorder(tree->left, func);
        func(tree->n);
        binary_tree_inorder(tree->right, func);
    }
}
