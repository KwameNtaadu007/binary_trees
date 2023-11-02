#include "binary_trees.h"


/**
 * binary_tree_nodes - Counts nodes with at least 1 child in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count the number of nodes.
 *
 * Return: The number of nodes with at least one child. Returns 0 if the tree is NULL.
 */


size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right != NULL || tree->left != NULL)
		return  (1 + binary_tree_nodes(tree->right) +
			 binary_tree_nodes(tree->left));
	return (0);
}
