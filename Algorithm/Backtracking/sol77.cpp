//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/combinations/


#include <iostream>
#include <vector>

using namespace std;
void dfs(vector<vector<int>> &res, vector<int> &tmp, int index, const int n, const int k) {
    if (index == k) {
        res.push_back(tmp);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (tmp.size() > 0 && tmp.back() >= i) continue;
        tmp.push_back(i);
        dfs(res, tmp, index+1, n, k);
        tmp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    if (k > n) return res;
    vector<int> tmp;
    dfs(res, tmp, 0, n, k);
    return res;
}
int main() {
    vector<vector<int>> res = combine(4, 2);
    for (auto list : res) {
        cout << "[";
        for (auto c: list)
            cout << c << " ";
        cout << "]\n";
    }
    return 0;
}


