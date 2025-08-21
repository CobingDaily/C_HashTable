#include "bitree.h"
#include <stddef.h>
#include <stdlib.h>

bi_tree* new_bi_tree(int data)
{
    bi_tree* tree = (bi_tree*) malloc(sizeof(bi_tree));
    if (!tree)
    {
        return NULL;
    }

    tree->data = data;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
    return tree;
}

bi_tree* bi_tree_insert(bi_tree* root, int data)
{
    if (root == NULL)
    {
        return new_bi_tree(data);
    }

    if (data < root->data)
    {
        root->leftChild = bi_tree_insert(root->leftChild, data);
    }
    else if (data > root->data)
    {
        root->rightChild = bi_tree_insert(root->rightChild, data);
    }

    return root;
}

void free_bi_tree(bi_tree* root)
{
    if (root == NULL) return;

    free_bi_tree(root->leftChild);
    free_bi_tree(root->rightChild);

    free(root);
}