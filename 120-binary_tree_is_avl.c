#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, 0 if the tree is NULL.
 */
size_t height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t l = tree->left ? 1 + height(tree->left) : 1;
    size_t r = tree->right ? 1 + height(tree->right) : 1;

    return ((l > r) ? l : r);
}

/**
 * is_avl_helper - Recursively checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited thus far.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
    if (tree == NULL)
        return (1);

    if (tree->n < lo || tree->n > hi)
        return (0);

    size_t lhgt = height(tree->left);
    size_t rhgt = height(tree->right);
    size_t diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;

    if (diff > 1)
        return (0);

    return (is_avl_helper(tree->left, lo, tree->n - 1) &&
            is_avl_helper(tree->right, tree->n + 1, hi));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return is_avl_helper(tree, INT_MIN, INT_MAX);
}

