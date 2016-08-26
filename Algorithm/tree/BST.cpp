//
// Created by BranY on 2016/8/1.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;
typedef int elemType;
struct BSTNode {
    elemType val;
    BSTNode *left, *right;
    BSTNode(elemType v) : val(v) , left(NULL), right(NULL) {}
};
/**
 * 先序遍历
 * @param T
 */
void preOrder(BSTNode* T) {
    if (T != NULL) {
        cout << T->val << " ";
        preOrder(T->left);
        preOrder(T->right);
    }
}
void preOrder_NotRec(BSTNode *T) {
    stack<BSTNode*> st;
    BSTNode *p = T;
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
void midOrder(BSTNode* T) {
    if (T != NULL) {
        midOrder(T->left);
        cout << T->val << " ";
        midOrder(T->right);
    }
}
vector<int> midOrder_NorRec(BSTNode* T) {
    stack<BSTNode*> st;
    vector<int> res;
    BSTNode *p = T;
    while (p != NULL || !st.empty()) {
        while (p != NULL) {
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            //cout << p->val << " ";
            res.push_back(p->val);
            st.pop();
            p = p->right;
        }
    }
    return res;
}
/**
 * 后序遍历
 * @return
 */
void postOrder(BSTNode* T) {
    if (T != NULL) {
        postOrder(T->left);
        postOrder(T->right);
        cout << T->val << " ";
    }
}
void postOrder_NorRec(BSTNode* T) {
    stack<BSTNode*> st;
    BSTNode *cur;
    BSTNode *pre = NULL;
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
 * 找最小值
 * @return
 */
BSTNode* findMin(BSTNode *root) {
    if (root == NULL) return NULL;
    else if (root->left == NULL) return root;
    else
        return findMin(root->left);
}
/**
 *找最大值
 * @param root
 * @return
 */
BSTNode* findMax(BSTNode *root) {
    if (root == NULL) return NULL;
    else if (root->right == NULL) return root;
    else return findMax(root->right);
}
/**
 * 判断val是否在BST中
 * @param root
 * @param val
 * @return
 */
bool contains(BSTNode *root, const elemType &val) {
    if (root == NULL) return false;
    else if (root->val > val)
        return contains(root->left, val);
    else if (root->val < val)
        return contains(root->right, val);
    else return true;
}
/**
 * 插入一个节点
 * @param root
 * @param val
 */
void insertNode(BSTNode *&root, const elemType &val) {
    if (root == NULL) {
        root = new BSTNode(val);
//        root = (BSTNode*)malloc(sizeof(BSTNode));
//        root->val = val;
//        root->left = root->right = NULL;
    }
    else if (root->val > val)
        insertNode(root->left, val);
    else if (root->val < val)
        insertNode(root->right, val);
}
/**
 * 删除一个节点
 * 1. 删除的节点没有孩子节点
 * 2. 删除的节点只有一个孩子节点
 * 3. 删除的节点有两个孩子节点：
 *                         找到右子树上的最小值，并替换当前父节点的值，之后删除最小值节点
 * @param root
 * @param val
 */
void removeNode(BSTNode *&root, const elemType &val) {
    if (root == NULL) return;
    if (root->val > val)
        removeNode(root->left, val);
    else if (root->val < val)
        removeNode(root->right, val);
    else if (root->left != NULL && root->right != NULL) {
        //3()
        root->val = findMin((root->right))->val;
        removeNode(root->right, root->val);
    } else if (root->left == NULL || root->right == NULL) {
        //2
        BSTNode *tmp = root;
        root = (root->left != NULL) ? root->left : root->right;
        delete tmp;

    } else if (root->left == NULL && root->right == NULL) {
        //1
        delete root;
        root = NULL;//避免成为野指针
    }
}
void convertNode(BSTNode *root, BSTNode **pLast) {
    if (root == NULL) return;
    BSTNode *cur = root;
    if (cur->left != NULL)
        convertNode(cur->left, pLast);
    cur->left = *pLast;
    if (*pLast != NULL) {
        (*pLast)->right = cur;
    }
    *pLast = cur;
    if (cur->right != NULL)
        convertNode(cur->right, pLast);
}
BSTNode* convertLinkedList(BSTNode *root) {
    BSTNode *pLast = NULL;
    convertNode(root, &pLast);
    BSTNode *pHead = pLast;
    while (pHead != NULL && pHead->left != NULL)
        pHead = pHead->left;
    return pHead;
}

int main()
{
    vector<int> arr{9,15,16,17,20,23,21,40,66,56,88};
    BSTNode *root = NULL;
    for (int i = 0; i < arr.size(); i++)
        insertNode(root, arr[i]);
    cout << "middle Order" << endl;
    midOrder(root);

    if (contains(root, 22))
        cout << "\nYES" << endl;
    if (contains(root, 23))
        cout << "\nYES" << endl;

    insertNode(root, 22);
    cout << "middle Order" << endl;
    midOrder(root);
    cout << "\nMiddle Order Not Recursive:\n";
    vector<int> res = midOrder_NorRec(root);
    for (auto c: res)
        cout << c << " ";
    cout << endl;
    cout << "\nMax " << findMax(root)->val << endl;
    cout << "Min "<< findMin(root)->val << endl;

    removeNode(root, 9);
    cout << "\nDelete 9, middle Order" << endl;
    midOrder(root);

    removeNode(root, 22);
    cout << "\nDelete 22, middle Order" << endl;
    midOrder(root);

    removeNode(root, 20);
    cout << "\nDelete 20, middle Order" << endl;
    midOrder(root);
    return 0;
}
