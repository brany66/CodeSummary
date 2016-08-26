//
// Created by BranY on 2016/7/31.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://blog.csdn.net/luckyxiaoqiang/article/details/7518888
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;
/**
 * 数组存储：父节点i, 左孩子：2*i 右孩子： 2*i + 1
 */
typedef int elemType;
struct treeNode {
    elemType val;
    treeNode *left, *right;
    treeNode(elemType v) : val(v) , left(NULL), right(NULL) {}
};
/**
 * 先序遍历
 * @param T
 */
void preOrder(treeNode* T) {
    if (T != NULL) {
        cout << T->val << " ";
        preOrder(T->left);
        preOrder(T->right);
    }
}
void preOrder_NotRec(treeNode *T) {
    stack<treeNode*> st;
    treeNode *p = T;
    while (p != NULL || !st.empty()) {
        while (p != NULL) {
            cout << p->val << " ";
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
}
/**
 * 中序遍历
 * @return
 */
void midOrder(treeNode* T) {
    if (T != NULL) {
        midOrder(T->left);
        cout << T->val << " ";
        midOrder(T->right);
    }
}
void midOrder_NorRec(treeNode* T) {
    stack<treeNode*> st;
    treeNode *p = T;
    while (p != NULL || !st.empty()) {
        while (p != NULL) {
            //cout << p->val << " ";
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            cout << p->val << " ";
            st.pop();
            p = p->right;
        }
    }
}
/**
 * 后序遍历
 * @return
 */
void postOrder(treeNode* T) {
    if (T != NULL) {
        postOrder(T->left);
        postOrder(T->right);
        cout << T->val << " ";
    }
}
void postOrder_NorRec(treeNode* T) {
    stack<treeNode*> st;

    treeNode *cur;
    treeNode *pre = NULL;
    st.push(T);
    while (!st.empty()) {
        cur = st.top();
        if ((cur->left == NULL && cur->right == NULL) ||
                (pre != NULL && (pre == cur->left || pre == cur->right))) {
            cout << cur->val <<  " ";
            st.pop();
            pre = cur;
        } else {
            if (cur->right != NULL)
                st.push(cur->right);
            if (cur->left != NULL)
                st.push(cur->left);
        }
    }
}
/**
 * 层次遍历
 * @return
 */
void levelOrder(treeNode* T) {
    queue<treeNode*> q;
    treeNode *t;
    q.push(T);
    while (!q.empty()) {
        t = q.front();
        if (t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
        q.pop();
        cout << t->val << " ";
    }
}
/**
 * 建立树
 * @param root
 * @param ch
 */
void createTree(treeNode* root, int ch) {
    treeNode *node = (treeNode*)malloc(sizeof(treeNode));
    node->val = ch;
    node->left = node->right = NULL;

    treeNode *back;
    treeNode *cur = root;
    while (cur != NULL) {
        back = cur;
        if (cur->val > ch)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (back->val > ch)
        back->left = node;
    else
        back->right = node;
}

/**
 * 统计节点数目
 * @return
 */
int countNode(treeNode* root) {
    if (root == NULL)
        return 0;
    else
        return countNode(root->left) + countNode(root->right) + 1;
}
/**
 * 计算树的深度
 * @param root
 * @return
 */
int maxDepth(treeNode* root) {
    if (!root) return 0;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}
/**
 * 利用先序遍历串和中序遍历串构建二叉树
 * @return
 */
void buildTree_1(string midOrder, string preOrder, treeNode* &root) {
    string L, R, preL, preR;
    bool flag = false;
    for (int i = 0; i < midOrder.size(); i++) {
        if (midOrder[i] == preOrder[0]) {
            flag = true;
            continue;
        }
        if (!flag) {
            L.push_back(midOrder[i]);
            preL.push_back(preOrder[i+1]);
        } else {
            R.push_back(midOrder[i]);
            preR.push_back(preOrder[i]);
        }
    }
    root->val = preOrder[0];
    if(L.size()) {
        root->left = (treeNode*)malloc(sizeof(treeNode));
        root->left = NULL;
        buildTree_1(L, preL, root->left);
    }
    if(R.size()) {
        root->right = (treeNode*)malloc(sizeof(treeNode));
        root->right = NULL;
        buildTree_1(R, preR, root->right);
    }
}

typedef vector<int>::iterator Iter;
treeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend){
    if(istart == iend) return NULL;
    int rootVal = *pstart;
    Iter iter = find(istart, iend, rootVal);
    treeNode *res = new treeNode(rootVal);

    res->left = buildTreeRecur(istart, iter, pstart+1, pstart + 1 + (iter-istart));
    res->right = buildTreeRecur(iter+1, iend, pstart+1+(iter-istart), pend);
    return res;
}
treeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTreeRecur(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
}

/**
 * 利用中序遍历串和后序遍历串构建二叉树
 * @return
 */
void buildTree_2(string midOrder, string postOrder, treeNode *&root) {
    string L, R, postL, postR;
    bool flag = false;
    for (int i = 0; i < midOrder.size(); i++) {
        if (midOrder[i] == postOrder[postOrder.size() - 1]) {
            flag = true;
            continue;
        }
        if  (!flag) {
            L.push_back(midOrder[i]);
            postL.push_back(postOrder[i]);
        } else {
            R.push_back(midOrder[i]);
            postR.push_back(postOrder[i-1]);
        }
    }
    root->val = postOrder[postOrder.size() - 1];
    if (L.size()) {
        root->left = (treeNode*)malloc(sizeof(treeNode));
        root->left = NULL;
        buildTree_2(L, postL, root->left);
    }
    if (R.size()) {
        root->right =  (treeNode*)malloc(sizeof(treeNode));
        root->right = NULL;
        buildTree_2(R, postR, root->right);
    }
}
int main()
{
    vector<int> nums{100, 4, 2, 3, 15, 35, 6, 45, 55, 20, 1, 14, 56, 57, 58};
    treeNode root(nums[0]);
    for(int i = 1; i < nums.size(); i++)
        createTree(&root, nums[i]);

    cout << "pre Order" << endl;
    preOrder(&root);
    cout << "\npre Order not recursive " << endl;
    preOrder_NotRec(&root);

    vector<elemType> num1;

    cout << "\nmid Order" << endl;
    midOrder(&root);
    cout << "\nmid Order not recursive" << endl;
    midOrder_NorRec(&root);

    cout << "\npost Order" << endl;
    postOrder(&root);
    cout << "\npost Order not recursive " << endl;
    postOrder_NorRec(&root);

    cout << "\nlevel Order" << endl;
    levelOrder(&root);
    return 0;
}
