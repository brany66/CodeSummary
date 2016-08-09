//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/combination-sum/

// https://leetcode.com/problems/combination-sum-iii/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void dfs(vector<int> &candidate, vector<int> &tmp, int index, int target, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(tmp);
        return;
    }
    if (target < 0) return;
    for (int i = index; i < candidate.size(); i++) {
        if (i > 0 && candidate[i] == candidate[i-1]) continue;
        tmp.push_back(candidate[i]);
        dfs(candidate, tmp, i, target - candidate[i], res);
        tmp.pop_back();
    }
}
void dfs_40(vector<int> &candidate, vector<int> &tmp, int index, int target, vector<vector<int>> &res) {

    if (target == 0) {
        res.push_back(tmp);
        return;
    }
    if (target < 0 || index >= candidate.size()) return;
    for (int i = index; i < candidate.size(); i++) {
        if (i > index && candidate[i] == candidate[i-1]) continue;
        tmp.push_back(candidate[i]);
        dfs_40(candidate, tmp, i+1, target - candidate[i], res);
        tmp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    if (candidates.size() < 1) return res;
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    dfs_40(candidates, tmp, 0, target, res);
    return res;
}

void dfs_216(vector<vector<int>> &res, vector<int> &tmp, int k, int n, int index) {
    if (index > n || k < 0 || (index < n && k == 0)) return;
    if (index == n && k == 0) {
        //sort(tmp.begin(), tmp.end());
        res.push_back(tmp);
        return;
    }
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        vector<int>::iterator it = tmp.begin();
        while (it != tmp.end()) {
            if (*it == i) {
                flag = true;
                break;
            }
            it++;
        }

        if (i + index > n || flag || (tmp.size() > 0 && tmp.back() >= i)) continue;
        tmp.push_back(i);
        dfs_216(res, tmp, k-1, n, index+i);
        tmp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    if (k > n || (n < 0)) return res;
    vector<int> tmp;
    dfs_216(res, tmp, k, n, 0);
    return res;
}
int main()
{
    vector<int> test{2,3,6,7};
    vector<int> test1{10,1,2,7,6,1,5};
    vector<vector<int>> res = combinationSum(test1, 8);
    for (auto a : res) {
        cout << "[";
        if (a.size() > 0) {
            for (auto b : a)
                cout << b << " ";
        }
        cout << "]\n";
    }
    cout << "**********************************************************\n";
    vector<vector<int>> list = combinationSum3(3, 9);
    for (auto a : list) {
        cout << "[";
        if (a.size() > 0) {
            for (auto b : a)
                cout << b << " ";
        }
        cout << "]\n";
    }
    return 0;
}