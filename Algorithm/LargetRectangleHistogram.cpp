//
// Created by BranY on 2016/7/27.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/**
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 * @param heights
 * @return
 */
int largestRectangleArea(vector<int>& heights) {
    vector<int> s;
    //考虑最后一个bar和只有一个bar的情况
    heights.push_back(0);
    int sum = 0;
    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[i] > heights[s.back()]) {
            s.push_back(i);
            i++;
        } else {
            int t = s.back();
            s.pop_back();
            sum = max(sum, heights[t] * (s.empty() ? i : i - s.back() - 1));
        }
    }
    return sum;
}

int main(){
    int N;
    while (cin >> N) {
        vector<int> arr(N, 0);
        for (int i= 0; i < N; i++) cin >> arr[i];
        cout << largestRectangleArea(arr) << endl;
    }
    return 0;
}