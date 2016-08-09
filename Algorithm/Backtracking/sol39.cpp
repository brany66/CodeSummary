//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void dfs(vector<int> &candidate, vector<int> &tmp, int index, int target, vector<vector<int>> &res) {
    if (target < 0) return;
    if (target == 0) {
        res.push_back(tmp);
        return;
    }
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
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if (candidates.size() < 1) return res;
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    dfs_40(candidates, tmp, 0, target, res);
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
    return 0;
}