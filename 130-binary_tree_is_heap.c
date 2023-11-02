#include "binary_trees.h"

/**
 * is_max_heap - Check if a binary tree is a Max Binary Heap.
 * @tree: Pointer to the root of the tree.
 * @index: Current index.
 * @cnodes: Total number of nodes.
 * @parent_value: Value of the parent node.
 * 
 * Return: 1 if it's a Max Binary Heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree, int index, int cnodes, int parent_value)
{
	if (tree == NULL)
		return (1);

	if (index >= cnodes)
		return (0);

	if (tree->n > parent_value)
		return (0);

	return (is_max_heap(tree->left, 2 * index + 1, cnodes, tree->n) &&
			is_max_heap(tree->right, 2 * index + 2, cnodes, tree->n));
}

/**
 * binary_tree_is_heap - Check if a binary tree is a Max Binary Heap.
 * @tree: Pointer to the root of the tree.
 * 
 * Return: 1 if it's a Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int cnodes = binary_tree_size(tree);

	return is_max_heap(tree, 0, cnodes, INT_MAX);
}

