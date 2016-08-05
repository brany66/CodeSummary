//
// Created by BranY on 2016/8/5.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
//#pragma pack(4)

using namespace std;
typedef struct treeNode {
    int weight;
    int parent;
    int left, right;
} HTNode, *huffmanTree;

typedef char **huffmanCode;
/**
 * 1. 1颗有n个叶子节点的哈夫曼树有2n-1个节点
 * @param weight
 * @return
 */

int Min(huffmanTree ht, int k) {
    int i = 0, min, min_weight;
    while (ht[i].parent != -1) i++;
    min_weight = ht[i].weight;
    min = i;
    for (; i < k; i++) {
        if (ht[i].weight < min_weight && ht[i].parent == -1) {
            min_weight = ht[i].weight;
            min = i;
        }
    }
    ht[min].parent = 1;
    return min;
}
void select_min(huffmanTree ht, int k, int &min1, int &min2) {
    min1 = Min(ht, k);
    min2 = Min(ht, k);
}
huffmanTree creat_huffmanTree(vector<int> &weight) {
    int total = 2 * weight.size() - 1;
    huffmanTree root = (huffmanTree)malloc(total * sizeof(HTNode));
    if (!root) {
        cout << "malloc failed" << endl;
        exit(-1);
    }
    int i, n = weight.size();
    for (i = 0; i < n; i++) {
        root[i].parent = -1;
        root[i].left = -1;
        root[i].right = -1;
        root[i].weight = weight[i];
    }
    for (; i < total; i++) {
        root[i].parent = -1;
        root[i].left = -1;
        root[i].right = -1;
        root[i].weight = 0;
    }
    int min1, min2;
    for (i = n; i < total; i++) {
        select_min(root, i, min1, min2);
        root[min1].parent = i;
        root[min2].parent = i;

        root[i].left = min1;
        root[i].right = min2;
        root[i].weight = root[min1].weight + root[min2].weight;
    }

    return root;
}
void huffmanCoding(huffmanTree ht, huffmanCode &hc, int n) {
    hc = (huffmanCode)malloc(n * sizeof(char *));
    if (!hc) {
        cout << "malloc failed" << endl;
        exit(-1);
    }
    char *code = (char *)malloc(n * sizeof(char));
    if (!code) {
        cout << "malloc failed" << endl;
        exit(-1);
    }
}
int main()
{
    return 0;
}