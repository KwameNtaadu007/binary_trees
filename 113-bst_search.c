#include "binary_trees.h"

/**
 * bst_search - Searches for a node with a specific value in a BST.
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: If the node with the specified value is found, a pointer to that node.
 *         If the node is not found or if the tree is NULL, returns NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return NULL;

	if (value == tree->n)
		return (bst_t *)tree;

	if (value < tree->n)
		return bst_search(tree->left, value);
	else
		return bst_search(tree->right, value);

	return NULL; // This line is not reachable; you can remove it.
}



