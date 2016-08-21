//
// Created by BranY on 2016/8/21.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/contest/1/problems/lexicographical-numbers/

#include <iostream>
#include <vector>

using namespace std;
void help(vector<int> &nums, int n, int carry) {
    nums.push_back(carry);
    int cin = 10;
    int k = carry * cin;
    if (k > n) return;
    while (k <= n) {
        nums.push_back(k);
        cin  *= 10;
        k = carry * cin;
    }
    k /= 10;
    while (k > 10) {
        int cur = k;
        int j = 1;
        while (j < 10) {
            cur += j;
            if (cur <= n) nums.push_back(cur);
            if (cur == n) break;
            ++j;
        }
        if (nums.size() == n) break;
        k /= 10;
    }
    while (k <=  n) {
        int cur = k;
        ++cur;
        while (cur < (carry + 1) * cin) {
            if (cur <= n) nums.push_back(cur);
            if (cur == n) break;
            ++cur;
        }
        if (cur >= n) break;
        cin *= 10;
        k = carry * cin;
    }
}
vector<int> lexicalOrder(int n) {
    vector<int> res;
    if (n <= 0) return res;
    for (int i = 1; i < 10; i++) {
        help(res, n, i);
        if (res.size() == n) break;
    }
    return res;
}
int main() {
    int n;
    while (cin >> n) {
        vector<int> res = lexicalOrder(n);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl << res.size() << endl;
    }
    return 0;
}
