#pragma once

struct BiTreeNode {
    int value;
    struct BiTreeNode* leftChild;
    struct BiTreeNode* rightChild;
};

typedef struct BiTreeNode bi_tree;