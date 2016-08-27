//
// Created by BranY on 2016/8/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <algorithm>
/**
 * https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/03.03.md
 * 所谓LCA，是当给定一个有根树T时，对于任意两个结点u、v，
 * 找到一个离根最远的结点x，使得x同时是u和v的祖先，x 便是u、v的最近公共祖先。
 */
using namespace std;
typedef int elemType;
struct treeNode {
    elemType val;
    treeNode *left, *right;
    treeNode(elemType v) : val(v) , left(NULL), right(NULL) {}
};
//1. 暴力
/**
 * 是二叉查找树
 * 1. 如果当前结点t 大于结点u、v，说明u、v都在t 的左侧，所以它们的共同祖先必定在t 的左子树中，故从t 的左子树中继续查找
 * 2. 如果当前结点t 小于结点u、v，说明u、v都在t 的右侧，所以它们的共同祖先必定在t 的右子树中，故从t 的右子树中继续查找
 * 3. 如果当前结点t 满足 u <t < v，说明u和v分居在t 的两侧，故当前结点t 即为最近公共祖先
 * 4. 而如果u是v的祖先，那么返回u的父结点，同理，如果v是u的祖先，那么返回v的父结点
 * @return
 */
treeNode *get_BST_LCA(treeNode *root, treeNode *u, treeNode *v) {
    if (!root) return NULL;
    if (u->val < root->val && v->val < root->val)
        return get_BST_LCA(root->left, u, v);
    else if(u->val > root->val && v->val > root->val)
        return get_BST_LCA(root->right, u, v);
    else
        return root;
    return NULL;
}
//不是BST
treeNode* getLCA(treeNode* root, treeNode* node1, treeNode* node2) {
    if(root == NULL)
        return NULL;
    if(root== node1 || root==node2)
        return root;

    treeNode* left = getLCA(root->left, node1, node2);
    treeNode* right = getLCA(root->right, node1, node2);

    if(left != NULL && right != NULL)
        return root;
    else if(left != NULL)
        return left;
    else if (right != NULL)
        return right;
    else
        return NULL;
}

//2. Tarjan算法 ,是一个在图中寻找强连通分量的算法。
/**
 * 任选一结点开始进行深度优先搜索dfs（若深度优先搜索结束后仍有未访问的结点，则再从中任选一点再次进行)
 * 搜索过程中已访问的结点不再访问。搜索树的若干子树构成了图的强连通分量。
 * Tarjan算法流程为：
 * Procedure dfs（u）；
    begin
        设置u号节点的祖先为u
        若u的左子树不为空，dfs（u - 左子树）；
        若u的右子树不为空，dfs（u - 右子树）；
        访问每一条与u相关的询问u、v
            -若v已经被访问过，则输出v当前的祖先t（t即u,v的LCA）
        标记u为已经访问，将所有u的孩子包括u本身的祖先改为u的父亲
    end
 */
const int MAXN = 1000;
//3. RMQ
void processRMQ(int Mat[MAXN][MAXN], int A[MAXN], int N) {
    int i, j;
    //initialize M for the intervals with length 1

    for (i = 0; i < N; i++)
        Mat[i][0] = i;

    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[Mat[i][j - 1]] < A[Mat[i + (1 << (j - 1))][j - 1]])
                Mat[i][j] = Mat[i][j - 1];
            else
                Mat[i][j] = Mat[i + (1 << (j - 1))][j - 1];
}
int main()
{
    vector<int> res;
    res.vector(res.begin() + 1, res.end());
    return 0;
}