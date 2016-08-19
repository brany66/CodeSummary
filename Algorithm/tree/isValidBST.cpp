//
// Created by BranY on 2016/8/15.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/validate-binary-search-tree/

#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <cstdlib>
#include <sstream>

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
/**
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * @param root
 * @return
 */
int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (root->left == NULL || root->right == NULL)
        return max( minDepth(root->left)+1, minDepth(root->right)+1 );
    return min( minDepth(root->left)+1, minDepth(root->right)+1 );
}
/**
 * Given a binary tree, determine if it is height-balanced.
 * @param p
 * @return
 */
int height(TreeNode *p) {
    if (!p) return 0;
    return max(height(p->left), height(p->right)) + 1;
}
bool isBalanced(TreeNode* root) {
    if (!root) return true;
    return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
}

/***
 * 99. Recover Binary Search Tree
 * @return
 */
TreeNode *pre1 = NULL, *first = NULL, *second = NULL;
void inOrder(TreeNode *root) {
    if (!root) return;
    inOrder(root->left);

    if (pre1 && pre1->val > root->val) {
        if (!first) first = pre1;
        second = root;
    }
    pre1 = root;
    inOrder(root->right);
}
void recoverTree(TreeNode* root) {
    if (!root) return;
    inOrder(root);
    swap(first->val, second->val);
}
/**
 * https://leetcode.com/problems/path-sum/
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * @param root
 * @param sum
 * @return
 */
bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (root && root->val == sum && !root->left && !root->right) return true;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

void dfs(TreeNode *root, vector<vector<int>> &res, vector<int> &tmp, int sum) {
    if (!root) return;
    tmp.push_back(root->val);
    if (!root->left && !root->right && sum == root->val) res.push_back(tmp);
    dfs(root->left, res, tmp, sum - root->val);
    dfs(root->right, res, tmp, sum - root->val);

    tmp.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if (!root) return res;
    vector<int> tmp;
    dfs(root, res, tmp, sum);
    return res;
}

int main() {
    vector<int> tmp;
    tmp.erase(tmp.end() - 1);
    stringstream ss;
    return 0;
}
