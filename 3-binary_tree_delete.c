#include "binary_trees.h"
/**
 * binary_tree_delete - func frees an entire tree using recursion it free the node
 * x when the node left and right are NULL
 * @tree: tree being freed
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        if (tree != NULL)
        {
            binary_tree_delete(tree->left);
            binary_tree_delete(tree->right);
        }
        free(tree);
    }
}
