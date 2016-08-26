//
// Created by BranY on 2016/8/26.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
typedef int elemType;
struct TreeNode {
    elemType val;
    TreeNode *left, *right;
    TreeNode(elemType v) : val(v) , left(NULL), right(NULL) {}
};
TreeNode *getNode(TreeNode* root, int path, int h) {
    while (h-- && root) {
        if (path & (1 << h))
            root = root->right;
        else
            root = root->left;
    }
    return root;
}
int countNodes(TreeNode *root) {
    int depth = 0;
    TreeNode *p = root;
    while (p) {
        depth++;
        p = p->left;
    }
    if (depth == 0) return 0;
    int left = 0, right = (1 << (depth - 1)) - 1;
    while (left <= right) {
        int m = (left + right) >> 1;
        if (getNode(root, m, depth - 1)) {
            left = m + 1;
        } else {
            right = m - 1;
        }
    }
    return (1 << (depth - 1)) + right;
}
int main() {
    return 0;
}
