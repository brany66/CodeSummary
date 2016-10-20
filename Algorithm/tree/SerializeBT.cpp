//
// Created by BranY on 2016/8/27.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <cstdlib>
#include <unordered_set>

using namespace std;
typedef int elemType;
struct TreeNode {
    elemType val;
    TreeNode *left, *right;
    TreeNode(elemType v) : val(v) , left(NULL), right(NULL) {}
};
vector<string> split(const string &str, string delimit) {
    vector<string> results;
    int lastIndex = 0, index;

    while ((index = str.find(delimit, lastIndex)) != string::npos) {
        results.push_back(str.substr(lastIndex, index - lastIndex));
        lastIndex = index + delimit.size();
    }

    if (lastIndex != str.length()) {
        results.push_back(str.substr(lastIndex, str.size() - lastIndex));
    }

    return results;
}
vector<string> split_1(const string &str, string regex) {
    vector<string> res;
    int lastIndex = 0, index;
    while ((index = str.find(regex, lastIndex)) != string::npos) {
        res.push_back(str.substr(lastIndex, index - lastIndex));
        lastIndex = index + regex.size();
    }
    if (lastIndex != string::npos) {
        res.push_back(str.substr(lastIndex, str.size() - lastIndex));
    }
    return res;
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    vector<TreeNode*> res;
    res.push_back(root);
    for (int i = 0; i < res.size(); i++) {
        TreeNode *t = res[i];
        if (!t) continue;
        res.push_back(t->left);
        res.push_back(t->right);
    }

    while (res.size() > 0 && res[res.size() - 1] == NULL) res.pop_back();
    if(res.size() == 0) return "[]";

    stringstream ss;
    ss << "[" << res[0]->val;
    for (int i = 1; i< res.size(); i++) {
        if (res[i] == NULL)
            ss << ",#";
        else
            ss << "," << res[i]->val;
    }
    ss << "]";
    return ss.str();
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data == "[]") return NULL;
    vector<string> da = split(data.substr(1, data.size() - 2), ",");
    TreeNode *root = new TreeNode(atoi(da[0].c_str()));
    queue<TreeNode*> que;
    que.push(root);
    bool flag = true;
    for (int  i = 1; i < da.size(); i++) {
        if (da[i] != "#") {
            TreeNode *node = new TreeNode(atoi(da[i].c_str()));
            if (flag)
                que.front()->left = node;
            else
                que.front()->right = node;
            que.push(node);
        }
        if (!flag)
            que.pop();
        flag = !flag;
    }
    return root;
}

int main() {
    string test = "[1,2,3,4,#,5,6,#,7]";
    TreeNode *root = deserialize(test);
    cout << serialize(root) << endl;
    return 0;
}
