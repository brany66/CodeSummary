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
/* Solution78 */
void helper(vector<int>& nums, vector<int> tmp, int i , vector<vector<int>>& ans) {
    if (i == nums.size()) {
        ans.push_back(tmp);
        return;
    }
    tmp.push_back(nums[i]);
    helper(nums, tmp, i+1, ans);
    tmp.pop_back();
    helper(nums, tmp, i+1, ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    helper(nums, tmp, 0, ans);
    return ans;
}

/* Solution90 */
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

/* Solution 91 */
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
    vector<int> test{1,2,2};
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
    return 0;
}