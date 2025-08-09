#pragma once

struct BiTreeNode {
    int data;
    struct BiTreeNode* leftChild;
    struct BiTreeNode* rightChild;
};

typedef struct BiTreeNode bi_tree;

bi_tree* new_bi_tree(int data);

bi_tree* bi_tree_insert(bi_tree* root, int data);

void free_bi_tree(bi_tree* root);