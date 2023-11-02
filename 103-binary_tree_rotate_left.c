#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 *
 * @tree: A pointer to binary_tree_t.
 *
 * Return: A pointer to the new root node of the tree after rotation, or NULL.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		temp = tree->right->left;
		aux = tree->right;
		aux->parent = tree->parent;
		aux->left = tree;
		tree->parent = aux;
		tree->right = temp;
																							if (temp)
																								temp->parent = tree;
																							return (aux);
																						}
	return (NULL);
}
