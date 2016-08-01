//
// Created by BranY on 2016/8/1.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://www.hawstein.com/posts/binary-indexed-trees.html#ref

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 于是可以总结出,给定序列（数列）A，我们设一个数组C满足:
 * C[i] = A[i-2^k + 1 ~ i], k为i中末尾0的个数
 * @return
 */
int getSum(int k, vector<int>& nums) {
    int ans = 0;
    for (int i = k; i > 0; i -= (i & -i))
        ans += nums[i];
    return ans;
}
/**
 * 获取低位的1
 * @param freq
 * @param tree
 */
int lowBit(int x) {
    return x&-x;
}
/**
 * 构建树状数组
 * @param freq
 * @param tree
 */
void build(vector<int>& freq, vector<int>& tree) {
    tree.push_back(0);
    for (int i = 1; i < freq.size(); i++) {
        int start = i - (i & -i) + 1;
        int sum = 0;
        while (start <= i) {
            sum += freq[start++];
        }
        tree.push_back(sum);
    }
}
/**
 * 给定索引idx,读取累积前缀和
 * @return
 */
int readPrefixSum(int idx, vector<int> &tree) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
/**
 * 改变某个原始数组的值，并更新树状数组
 * @return
 */
void update(int idx, int val,vector<int> &tree) {
    while (idx < tree.size()) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
/**
 * 获取指定索引idx位置上的实际频率值
 * 1. readPrefixSum[idx] - readPrefixSum[idx-1]
 * freq[12] = C[12]-C[11]
 *
 * 2.
 * @param idx
 * @return
 */
int getRealVal(int idx, vector<int> &tree) {
    int sum = tree[idx];
    if (idx > 0) {
        int z = idx - (idx & -idx);
        idx--;
        while (idx != z) {
            sum -= tree[idx];
            idx -= (idx & -idx);
        }
    }
    return sum;
}

void scale(int c, vector<int>& tree) {
    for (int i =1; i < tree.size(); i++)
        tree[i] = tree[i]/c;
}
/**
 * 返回指定累积频率的索引
 * @return
 */

int main()
{
    vector<int> freq{0,1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
    vector<int> tree;
    build(freq, tree);

    for(auto c : tree)
        cout << c << " ";
    cout << endl;

    cout << getRealVal(12, tree) << endl;
    return 0;
}