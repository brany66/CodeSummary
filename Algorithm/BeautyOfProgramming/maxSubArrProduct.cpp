//
// Created by BranY on 2016/8/12.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <limits>
#include <vector>
#include <limits.h>
/**
 * 给定一个长度为N的数组，求出任意N-1个数组元素相乘的最大值
 */
using namespace std;
/**
 * s[0] = 1
 * s[i] = s[i-1] * a[i-1];
 * i -> [1, N-1]
 *
 * t[N] = 1
 * t[i] = t[i+1] * a[i];
 * i -> [1, N-1]
 *
 * P[i] = s[i-1] * t[i]
 */
int getMaxSubProduct(vector<int> &nums) {
    if (nums.size() <= 1) return 0;
    int N = nums.size();
    vector<int> s(N, 1);
    vector<int> t(N+1, 1);
    vector<int> p;

    int i;
    for (i = 1; i < N; i++) s[i] = s[i-1] * nums[i-1];
    for (i = N - 1; i >= 1; i--) t[i] = t[i+1] * nums[i];

    for (i = 1; i < N; i++) {
        p.push_back(s[i-1] * t[i]);
    }
    int  Max = INT_MIN;
    for (i = 0; i < p.size(); i++)
        Max = max(Max, p[i]);
    cout << Max << endl;
    return Max;
}
int main() {
    vector<int> test{1, 2, 3, 4, 5, -5, 7, 9, -10};
    cout << getMaxSubProduct(test) << endl;
    return 0;
}
