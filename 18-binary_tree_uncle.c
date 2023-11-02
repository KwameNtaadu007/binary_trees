#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 *
 * @node: Pointer to the node for which to find the sibling.
 *
 * Return: Pointer to the sibling node, or NULL if no sibling is found or if the input node is NULL.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->right == node)
		return (node->parent->left);
	else
		return (node->parent->right);

}
/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: Pointer to the node for which to find the uncle.
 *
 * Return: Pointer to the uncle node, or NULL if no uncle is found or if the input node is NULL.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
