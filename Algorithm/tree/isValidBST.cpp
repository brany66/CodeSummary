//
// Created by BranY on 2016/8/15.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/validate-binary-search-tree/

#include <iostream>
#include <climits>

using namespace std;
typedef int elemType;
struct TreeNode {
    elemType val;
    TreeNode *left, *right;
    TreeNode(elemType v) : val(v) , left(NULL), right(NULL) {}
};
TreeNode *pre = NULL;
bool validBST(TreeNode* root) {
    if (root == NULL) return true;
    if (!validBST(root->left))
        return false;
    if (pre != NULL && root->val <= pre->val)
        return false;
    pre = root;
    return validBST(root->right);
}
bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    return validBST(root);
}

bool isValidBST_2(TreeNode* root) {
    TreeNode *cur = root, *prev = NULL, *last = NULL;
    bool isValid = true;
    while (cur != NULL) {
        if (cur->left == NULL) {
            if (last != NULL && last->val >= cur->val) isValid = false;
            last = cur;
            cur = cur->right;
        } else {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur) { prev = prev->right; }
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                if (last->val >= cur->val) isValid = false;
                last = cur;
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return isValid;
}

int main() {
    return 0;
}
