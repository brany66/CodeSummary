//
// Created by BranY on 2016/8/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include<iostream>
#include<algorithm>
#include <numeric>
#include <cstdlib>
#include<vector>

using namespace std;
void rotatePart(vector<int>& nums, int start, int end) {
    while (start < end) {
        nums[start] = (nums[start] + nums[end]) - (nums[end] = nums[start]);
        start++;
        end--;
    }
}
void rotate(vector<int>& nums, int k) {
    if (k <= 0 || nums.size() == 0 || (k % nums.size() == 0))
        return;
    rotatePart(nums, 0, nums.size() - 1 - (k % nums.size()));
    rotatePart(nums, nums.size() - (k % nums.size()), nums.size() - 1);
    rotatePart(nums, 0, nums.size() - 1);
}
int main() {
    vector<int> nums(10, 0);

    int m;
    for (int i = 0; i < 10; i++) cin >> nums[i];
    cin >> m;
    rotate(nums, m);
    int i = 0;
    //double d = atof("1.111");
    int part1 = 0, part2 = 0;
    int c = m % 10;
    while (i < c) {
        part1 +=nums[i++];
    }
    c = m % 10;
    i = 9 - c + 1;
    while (i < 10) {
        part2 += nums[i++];
    }
    for (auto c: nums)
        cout << c << " ";
    cout << "\n" << part1 << " " << part2 << endl;

    //accumulate(nums.begin(), nums.end(), 0);
    return 0;
}