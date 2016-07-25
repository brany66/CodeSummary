//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
/**
 * 要求连续
 * Max Sub Array Sum
 */

int basicMethod(vector<int>& A) {
    int maxSum = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        int sum = 0;
        for (int j = i; j < A.size(); j++) {
            sum += A[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}

/**
 * 1. A[n-1]单独构成最大子数组
 * 2. 最大子数组以A[n-1]结尾
 * 3. 最大子数组跟A[n-1]没关系，最大子数组在A[0-n-2]范围内，转为考虑元素A[n-2]
 * So, Suppose:
 * A[n-1]结尾的最大子数组和是End[n-1]
 * [0, n-1]范围内的最大子数组和dp[n-1]
 * dp[n-1] = max {A[n-1], End[n-1], dp[n-2] }
 *
 * dp[i] = max {A[i], End[i-1] + A[i], dp[i-1]}
 */
int maxArrSum(vector<int>& A) {
    vector<int> End(100, -1);
    vector<int> dp(100, -1);
    End[0] = dp[0] = A[0];
    for (int i= 1; i < A.size(); i++) {
        End[i] = max(End[i-1]+A[i], A[i]);
        dp[i] = max(End[i], dp[i-1]);
    }
    return dp[A.size()-1];
}
/**
 * O(1) Space Complexity
 */
int maxArrSum_Pro(vector<int>& A) {
    int end = A[0], dp = A[0];
    for (int i = 1; i < A.size(); i++) {
        end = max(A[i], end + A[i]);
        dp = max(end, dp);
    }
    return dp;
}
/**
 * End[i] = max(End[i-1]+A[i], A[i]); 若End[i-1] < 0 则， End[i] = A[i]
 */
int maxArrSum1(vector<int>& A) {
    int maxSum = INT_MIN;
    int sum = 0;
    int curStart = 0, start = 0, end = 0;
    for (int i = 0; i < A.size(); i++) {
        if (sum < 0) {
            sum = A[i];
            curStart = i;
        }
        else
            sum += A[i];
        if (sum > maxSum) {
            maxSum = sum;
            start = curStart;
            end = i;
        }
    }
    return maxSum;
}
/**
 * 如果数组A[0]...A[n-1]首尾相邻成环
 * 1. 如果最大子数组跨界，则中间存在最小子数组和，且和一定为负数
 * 2. 如果最大子数组不跨界，则总值减去最小子数组不一定是最大子数组和,如{8,-10, 60, 3, -1, -6} 8, 60, 3, -1, -6
 * MaxSum ={原问题的最大子数组和， 总值-最小子数组和}
 */
int maxSum_endToend(vector<int>& A) {
    int maxSum1 = maxArrSum_Pro(A); //不跨界最大子数组和
    if (maxSum1 < 0) return maxSum1;

    int maxSum2 = INT_MIN;
    int totalSum = 0, minSum = INT_MAX, tmpMin = 0;
    for (int i = 0; i < A.size(); i++) {
        if (tmpMin < 0)
            tmpMin = A[i];
        else
            tmpMin += A[i];
        if (tmpMin < minSum)
            minSum = tmpMin;
        totalSum += A[i];
    }
    maxSum2 = totalSum - minSum;
    return max(maxSum1, maxSum2);
}
int main()
{
    vector<int> arr{1, -2, 3, 10, -4, 7, 2, 5}; //3, 10, -4, 7, 2
    vector<int> arr1{0, -2, 3, 5, -1, 2}; //9
    vector<int> arr2{-9, -2, -3, -5 , -3}; //-2

    cout << basicMethod(arr) << " " << basicMethod(arr1) << endl;

    cout << maxArrSum(arr) << " " << maxArrSum(arr1) << " " << maxArrSum(arr2) << endl;

    cout << maxArrSum_Pro(arr) << " " << maxArrSum_Pro(arr1) << " " << maxArrSum_Pro(arr2) << endl;

    cout << maxArrSum1(arr) << " " << maxArrSum1(arr1) << " " << maxArrSum1(arr2) << endl;

    vector<int> arr3{8,-10, 60, 3, -1, -6};
    vector<int> arr4{1,-2,3,5,-1,2};
    vector<int> arr5{-9,-2,-3,-5,-4,-6};

    cout << maxSum_endToend(arr3) << " "<< maxSum_endToend(arr4) << " "<< maxSum_endToend(arr5) << endl;
    return 0;
}
