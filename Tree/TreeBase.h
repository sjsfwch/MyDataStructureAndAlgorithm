#ifndef TREEBASE
#define TREEBASE
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
class TreeNode {
   public:
    int data;
    TreeNode *parent = nullptr, *lc = nullptr, *rc = nullptr;
    TreeNode(int n);
};

class Tree {
   public:
    TreeNode* root;
    Tree(std::vector<int>& A);
    // ~Tree();
    void traPreOrder();
    void traInOrder();
    void traPostOrder();
    void traLevelOrder();
};

#endif