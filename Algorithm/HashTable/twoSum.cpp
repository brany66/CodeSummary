//
// Created by BranY on 2016/8/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * @param nums
 * @param target
 * @return
 */
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        auto it = map.find(target - nums[i]);
        if (it != map.end()) {
            res[0] = i;
            res[1] = it->second;
            break;
        } else
            map[nums[i]] = i;
    }
    return res;
}
/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 */
vector<int> twoSum_2(vector<int>& numbers, int target) {
    vector<int> res(2, 0);
    unordered_map<int, int> map;
    for (int i = 0; i < numbers.size(); i++) {
        auto it = map.find(target - numbers[i]);
        if (it != map.end()) {
            res[0] = min(i+1, it->second);
            res[1] = max(i+1, it->second);
            break;
        } else
            map[numbers[i]] = i + 1;
    }
    return res;
}
vector<int> twoSum_2_2(vector<int>& numbers, int target) {
    if (numbers.empty()) return {};
    for (int i = 0; i < numbers.size(); i++) {
        int l = i + 1, r = numbers.size() - 1, gap = target - numbers[i];
        while (l <= r) {
            int m = (l + r) / 2;
            if (numbers[m] == gap)  return {i+1, m+1};
            else if (numbers[m] > gap) r = m - 1;
            else l = m + 1;
        }
    }
}
int main() {
    return 0;
}
