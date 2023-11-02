#include "binary_trees.h"

/**
 * binary_tree_insert_left - This function inserts a node as the left-child
 * @parent: A pointer that points to the node to insert the left-child in.
 * @value: The value to store in the new node.
 * Return: pointer to created node, or NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return (NULL);

    binary_tree_t *node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = parent->left;
    node->right = NULL;

    if (parent->left)
        parent->left->parent = node;
    
    parent->left = node;

    return (node);
}
