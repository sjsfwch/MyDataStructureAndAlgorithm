#include "TreeBase.h"

TreeNode::TreeNode(int n) {
    this->data = n;
}

Tree::Tree(std::vector<int>& A) {
    std::queue<TreeNode*> q;
    TreeNode* p = new TreeNode(A[0]);
    root = p;
    q.push(p);
    int i = 1;
    while (i < A.size()) {
        p = q.front();
        q.pop();
        if (!p) {  //空节点的两个孩子也是空的
            q.push(nullptr);
            q.push(nullptr);
            i += 2;
        } else {
            if (A[i] >= 0) {
                p->lc = new TreeNode(A[i]);
                p->lc->parent = p;
                q.push(p->lc);
            } else {
                q.push(nullptr);
            }
            i++;
            if (i >= A.size())
                break;
            if (A[i] >= 0) {
                p->rc = new TreeNode(A[i]);
                p->rc->parent = p;
                q.push(p->rc);
            } else {
                q.push(nullptr);
            }
            i++;
        }
    }
}

void Tree::traLevelOrder() {
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* p = q.front();
        q.pop();
        std::cout << p->data << " ";
        if (p->lc)
            q.push(p->lc);
        if (p->rc)
            q.push(p->rc);
    }
}

void Tree::traPreOrder() {
    std::stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* p = s.top();
        s.pop();
        std::cout << p->data << " ";
        if (p->rc)
            s.push(p->rc);
        if (p->lc)
            s.push(p->lc);
    }
}