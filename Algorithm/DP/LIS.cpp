//
// Created by BranY on 2016/7/22.
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// Contact at wyang@smail.nju.edu.cn
//

#include <iostream>
#include <vector>
using namespace std;
int dp[100];
/**
 * 子序列，不要求连续。这里，只说明获取最长子序列的长度
 * 1. to LCS （排序）
 * A[] ={5,6,7,1,2,8}
 * B[] ={1,2,5,6,7,8}
 *
 * dp[i]表示i时的最长递增子序列长度
 * 从后向前分析，很容易想到，第i个元素之前的最长递增子序列的长度要么是1（单独成一个序列），要么就是第i-1个元素之前的最长递增子序列加1，可以有状态方程：
 * LIS[i] = max{1,LIS[k]+1}，其中，对于任意的k<=i-1，arr[i] > arr[k]，这样arr[i]才能在arr[k]的基础上构成一个新的递增子序列。
 */
int LIS(vector<int>& A) {
    int res = 0 , i;
    for (i = 1; i < A.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp [i] = dp[j] + 1;
                if (dp[i] > res)
                    res = dp[i];
            }
        }
    }
    return res;
}

/**
 * 我们期望在前i个元素中的所有长度为len的递增子序列中找到这样一个序列，它的最大元素比A[i+1]小，而且长度要尽量的长，
 * 如此，我们只需记录len长度的递增子序列中最大元素的最小值就能使得将来的递增子序列尽量地长。
 *
 * 维护一个数组dp[i]，记录长度为i的递增子序列中最大元素的最小值，
 * 并对于数组中的每个元素考察其是哪个子序列的最大元素，二分更新dp数组，最终i的值便是最长递增子序列的长度。
 */
int BinarySearch(vector<int>& A, int size, int val) {
    int l = 0, r = size - 1;
    while (l <= r) {
        int m = l + (r - l)/2;
        if (A[m] <= val) l = m+1;
        else r = m - 1;
    }
    return l;
}
int LIS_BS(vector<int>& A) {
    vector<int>dp1(A.size()+1, 0);
    dp1[0] = A[0];
    int len = 1;
    for (int i = 1; i < A.size(); i++) {/* 最大元素，否则二分 */
        if (A[i] > dp1[len-1])
            dp1[len++] = A[i];
        else {
            int pos = BinarySearch(dp1, len, A[i]);
            dp1[pos] = A[i];
        }
    }
    return len;
}
int main()
{
    vector<int> A{1, -1, 2, -3, 4, -5, 6, -7}; //1,2,4,6
    cout << LIS(A) << endl;

    cout << LIS_BS(A) << endl;
    return 0;
}