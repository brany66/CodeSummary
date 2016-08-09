//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/permutations/
// https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void dfs_46(const vector<int> &nums, vector<vector<int>> & res, vector<int> &tmp, int index) {
    if (index == nums.size()) {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        vector<int>::iterator it = tmp.begin();
        bool flag = false;
        while (it != tmp.end()) {
            if (*it == nums[i])
                flag = true;
            it++;
        }
        if (flag) continue;
        tmp.push_back(nums[i]);
        dfs_46(nums, res, tmp, index+1);
        tmp.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) return res;
    vector<int> tmp;
    dfs_46(nums, res, tmp, 0);
    return res;
}

void dfs(const vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res, int index, vector<bool> &used) {
    if (index == nums.size()) {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && !used[i-1] && nums[i] == nums[i-1]) continue;
        if (!used[i]) {
            used[i] = true;
            tmp.push_back(nums[i]);
            dfs(nums, tmp, res, index+1, used);
            tmp.pop_back();
            used[i] = false;
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) return res;
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    vector<bool> used(nums.size(), false);
    dfs(nums, tmp, res, 0,used);
    return res;
}
int main() {
    vector<int> test_46={1,2,3};
    vector<vector<int>> res_46 = permute(test_46);
    for (auto list : res_46) {
        cout << "[";
        if (list.size() > 0) {
            for (auto c : list)
                cout << c << " ";
        }
        cout << "]\n";
    }
    cout << "*******************************************\n";
    vector<int> test={1,1,2};
    vector<vector<int>> res_47 = permuteUnique(test);
    for (auto list : res_47) {
        cout << "[";
        if (list.size() > 0) {
            for (auto c : list)
                cout << c << " ";
        }
        cout << "]\n";
    }
    return 0;
}

