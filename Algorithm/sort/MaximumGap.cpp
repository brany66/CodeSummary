//
// Created by BranY on 2016/9/4.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int MIN = nums[0], MAX = nums[0];
    for (auto c : nums) {
        MIN = min(c, MIN);
        MAX = max(c, MAX);
    }
    //the minimum of gap(gap的下界)
    int gap = (int)ceil(double(MAX - MIN) / (nums.size() - 1));
    vector<int> bucketsMIN(nums.size() - 1, INT_MAX);
    vector<int> bucketsMAX(nums.size() - 1, INT_MIN);

    for (auto c: nums) {
        if (c == MIN || c == MAX) continue;
        // index of the right position in the buckets
        int idx = (c - MIN) / gap;
        bucketsMIN[idx] = min(c, bucketsMIN[idx]);
        bucketsMAX[idx] = max(c, bucketsMAX[idx]);
    }

    int maxGap = INT_MIN;
    int prev = MIN;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (bucketsMIN[i]== INT_MAX && bucketsMAX[i] == INT_MIN) continue;

        // min value minus the previous value is the current gap
        maxGap = max(maxGap, bucketsMIN[i] - prev);
        prev = bucketsMAX[i];
    }
    // update the final max value gap
    maxGap = max(maxGap, MAX - prev);
    return maxGap;

}
int main() {
    vector<int> nums{3,5,6,2,4};
    return 0;
}
