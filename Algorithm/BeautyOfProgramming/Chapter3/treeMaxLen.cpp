//
// Created by BranY on 2016/9/6.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    int maxLeft, maxRight;
    TreeNode(int a) : val(a) , left(NULL), right(NULL){}
};
int maxLen = 0;
void findMaxLen(TreeNode *root) {
    if (root == NULL) return;
    if (root->left == NULL)
        root->maxLeft = 0;
    if (root->right == NULL)
        root->maxRight = 0;
    if (root->left != NULL)
        findMaxLen(root->left);
    if (root->right != NULL)
        findMaxLen(root->right);

    if (root->left != NULL) {
        int tmpMax = 0;
        if (root->left->maxLeft > root->left->maxRight)
            tmpMax = root->left->maxLeft;
        else
            tmpMax = root->left->maxRight;
        root->maxLeft = tmpMax + 1;
    }

    if (root->right != NULL) {
        int tmpMax = 0;
        if (root->right->maxLeft > root->right->maxRight)
            tmpMax = root->right->maxLeft;
        else
            tmpMax = root->right->maxRight;
        root->maxRight = tmpMax + 1;
    }

    //update
    if (root->maxLeft + root->maxRight > maxLen)
        maxLen = root->maxLeft + root->maxRight;
}
typedef union {
    long i;
    int k[5];
    char c;
} DATE;
struct data {
    int cat;
    DATE cow;
    double dog;
} too;
DATE MAX;
int main() {
    printf("%d",sizeof(struct data)+sizeof(MAX));
    const char *p = "ABC";
    if (p == "ABC")cout << "YES\n";
    return 0;
}
