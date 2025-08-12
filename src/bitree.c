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