#include "binary_trees.h"


/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 *
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    new_node = *tree;

    if (value < new_node->n)
    {
        if (new_node->left == NULL)
        {
            new_node->left = binary_tree_node(new_node, value);
            return (new_node->left);
        }
        return (bst_insert(&(new_node->left), value));
    }

    if (value > new_node->n)
    {
        if (new_node->right == NULL)
        {
            new_node->right = binary_tree_node(new_node, value);
            return (new_node->right);
        }
        return (bst_insert(&(new_node->right), value));
    }

    return (NULL); // Value already exists, return NULL.
}


