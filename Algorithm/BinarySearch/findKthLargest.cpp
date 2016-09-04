//
// Created by BranY on 2016/8/25.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest1(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), std::greater<int>());
    for (int i = 0; i < nums.size(); i++)
        if (i+1 == k) return nums[i];
    return 0;
}


int helper(vector<int> &nums, int l, int r, int k ) {
    if (l == r) return nums[l];

    int i = l, j = r;
    int pivot = nums[(i+j)/2];
    while (i <= j) {
        while (i <= j && nums[i] < pivot) i++;
        while (i <= j && nums[j] > pivot) --j;
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    if (r > i && k >= i) return helper(nums, i, r, k);
    if (l < j && k <= j) return helper(nums, l, j, k);
    return nums[k];
}
int findKthLargest(vector<int>& nums, int k) {
    return helper(nums, 0, nums.size() - 1, nums.size()- k);
}

typedef pair<int, int> P;
void topKFrequent(vector<int> &nums, int k, vector<int> &res) {
    unordered_map<int, int> cnt;
    for (auto c : nums) cnt[x]++;

    priority_queue<P, vector<P>, greater<p>> que;
    for (auto &x : cnt) {
        if (que.size() < k) {
            que.push(make_pair(x.second, x.first));
        } else {
            if (que.top().first < x.second) {
                que.pop();
                que.push(make_pair(x.second, x.first));
            }
        }
    }
    while (!que.empty()) {
        res.push_back(que.top().second);
        que.pop();
    }
}
int main() {
    vector<int> arr{3,2,1,5,6,4,7,8,9};
    int k ;
    // 1 <= k <= 9
    while (cin >> k) {
        cout << "kth " << k << " " << findKthLargest(arr, k) << endl;
    }
    return 0;
}
