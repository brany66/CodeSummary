//
// Created by BranY on 2016/8/15.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
typedef int elemType;
struct TreeNode {
    elemType val;
    TreeNode *left, *right;
    TreeNode(elemType v) : val(v) , left(NULL), right(NULL) {}
};
vector<TreeNode *> generateTree(int from, int to) {
    vector<TreeNode *> ret;
    if(to - from < 0) ret.push_back(0);
    if(to - from == 0) ret.push_back(new TreeNode(from));
    if(to - from > 0) {
        for(int i = from; i <= to; i++) {
            vector<TreeNode *> l = generateTree(from, i-1);
            vector<TreeNode *> r = generateTree(i+1, to);
            for(int j = 0; j < l.size(); j++) {
                for(int k = 0; k < r.size(); k++) {
                    TreeNode *h = new TreeNode (i);
                    h->left = l[j];
                    h->right = r[k];
                    ret.push_back(h);
                }
            }
        }
    }
    return ret;
}
vector<TreeNode*> generateTrees(int n) {
    return generateTree(1, n);
}
int main() {
    int n;
    while (cin >> n) {
        vector<TreeNode*> res = generateTrees(n);
    }
    return 0;
}
