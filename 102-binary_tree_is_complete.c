#include "binary_trees.h"
/**
 * new_node - creates new_node in linked_list
 * @node: pointer to created node
 * Return: created node
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *n;

	n =  malloc(sizeof(link_t));
	if (n == NULL)
	{
		return (NULL);
	}
	n->node = node;
	n->next = NULL;

	return (n);
}
/**
 * free_q - frees nodes at the linked list
 * @head: Node of the linked_list
 */
void free_q(link_t *head)
{
	link_t *tmpNode;

	while (head)
	{
		tmpNode = head->next;
		free(head);
		head = tmpNode;
	}
}
/**
 * _push - pushes a node into stack
 * @node: pointer of node of the tree
 * @head: Type head node of in the stack
 * @tail: Type tail node of in the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *n;

	n = new_node(node);
	if (n == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = n;
	*tail = n;
}
/**
 * _pop - Pops a node into the stack
 * @head: Type head node of in the stack
 */
void _pop(link_t **head)
{
	link_t *tmpNode;

	tmpNode = (*head)->next;
	free(*head);
	*head = tmpNode;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer of node of the tree
 * Return: 1 if complete || 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tl;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tl = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tl);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tl);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
