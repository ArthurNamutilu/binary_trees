#include "binary_trees.h"
/**
 * array_to_bst - funct yhat turns an arr to a BST tree
 * @array: the array to turns to BST tree
 * @size: array size
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t j = 0;
	bst_t *rt;

	rt = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; j < size; j++)
	{
		if (j == 0)
		{
			bst_insert(&rt, array[j]);
		}
		else
		{
			bst_insert(&rt, array[j]);
		}
	}
	return (rt);
}
