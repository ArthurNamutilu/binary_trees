#include "binary_trees.h"
/**
 * binary_tree_insert_right - adds a node in the right of the parent
 * if it exists it move down one level and add the new node first
 * @parent: parent of specified node
 * @value: val of the node
 * Return: NULL 
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *newNode;

    if (parent == NULL)
    {
        return (NULL);
    }

    newNode = binary_tree_node(parent, value);
    if (newNode == NULL)
    {
        return (NULL);
    }
    if (parent->right != NULL)
    {
        newNode->right = parent->right;
        parent->right->parent = newNode;
    }
    parent->right = newNode;
    return (newNode);
}
