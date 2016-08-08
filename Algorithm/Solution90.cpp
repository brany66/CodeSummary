//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
void dfs(vector<vector<int>> &list, vector<int> &tmp, vector<int>& nums, int l) {
    if (l == nums.size()) {
        list.push_back(tmp);
        return;
    }
    tmp.push_back(nums[l]);
    dfs(list, tmp, nums, l+1);
    tmp.erase(tmp.end()-1);
    dfs(list, tmp, nums, l+1);
}
bool equals(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size())
        return false;
    int len = a.size();
    for (int i = 0; i < len; i++)
        if (a[i] != b[i]) return false;
    return true;
}
void dfs_duplicate(vector<vector<int>> &list, vector<int> &tmp, vector<int>& nums, int l) {
    if (l == nums.size()) {
        int cnt = list.size();
        for (int i = 0; i< cnt; ++i)
            if (equals(list[i], tmp))
                return;
        list.push_back(tmp);
        return;
    }
    tmp.push_back(nums[l]);
    dfs_duplicate(list, tmp, nums, l+1);
    tmp.erase(tmp.end()-1);
    dfs_duplicate(list, tmp, nums, l+1);
}
void dfs_dup(vector<vector<int>> &list, vector<int> &tmp, vector<int>& nums, int l) {
    list.push_back(tmp);
    for (int i = l; i < nums.size(); i++) {
        if (i > l && nums[i] == nums[i-1]) continue;
        tmp.push_back(nums[i]);
        dfs_dup(list, tmp, nums, i+1);
        tmp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> list;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    dfs_dup(list, tmp, nums, 0);
    return list;
}
int numDecodings(string s) {
    //if (s == NULL) return 0;
    if (s.size() <= 1) return s.size();
    int *dp = new int[s.size()+1];
    dp[0] = 1;
    dp[1] = (s[0] != '0') ? 1 : 0;
    for (int i = 2; i <= s.size(); i++) {
        if (s[i-1] != '0')
            dp[i] = dp[i-1];
        int tmp = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        if (tmp >= 10 && tmp <= 26) {
            dp[i] += dp[i-2];
        }
    }
    return dp[s.size()];
}

int main()
{
    vector<int> test{1,2,2,3,3};
    vector<vector<int>> res = subsetsWithDup(test);
    for (auto list : res) {
        cout << "[";
        if (list.size() > 0) {
            for (auto c: list) {
                cout << c << " ";
            }
        }
        cout << "]" << endl;
    }
    string sss = "12";
    cout << numDecodings(sss) << endl;
    return 0;
}