#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *tree = NULL;
    avl_t *tmp;
    int i;
    set_t *set = NULL; // Assume you have a set data structure.

    if (array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        if (set_contains(set, array[i])) // Check for duplicates.
            continue;

        tmp = avl_insert(&tree, array[i]);
        if (tmp == NULL)
        {
            set_free(set); // Free the set if necessary.
            avl_delete(tree); // Delete the tree to avoid memory leaks.
            return (NULL);
        }
        set_insert(set, array[i]); // Add the element to the set.
    }

    set_free(set); // Free the set if necessary.
    return (tree);
}

