#include "binary_trees.h"


/**
 * is_bst_recursive - Checks if a binary tree is a Binary Search Tree (BST) recursively.
 *
 * @root: The root node of the binary tree.
 * @min: The minimum value the node can have (initially INT_MIN).
 * @max: The maximum value the node can have (initially INT_MAX).
 *
 * Return: 1 if it's a BST, 0 if it's not.
 */
int is_bst_recursive(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
		return (1);

	if (root->n <= min || root->n >= max)
		return (0);

	return (is_bst_recursive(root->left, min, root->n) &&
			is_bst_recursive(root->right, root->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a Binary Search Tree (BST).
 *
 * @tree: The root node of the binary tree.
 *
 * Return: 1 if it's a BST, 0 if it's not or tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_recursive(tree, INT_MIN, INT_MAX));
}

