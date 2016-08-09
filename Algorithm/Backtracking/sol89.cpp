//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/gray-code/

#include <iostream>
#include <vector>

using namespace std;
vector<int> grayCode(int n) {
    if (n < 0) {
        vector<int> x;
        return x;
    }
    if (n == 0){
        vector<int> res;
        res.push_back(0);
        return res;
    }
    vector<int> tmp = grayCode(n-1);
    int addNum = 1 << (n-1);
    vector<int> result(tmp);
    for(int i = tmp.size() - 1;i >= 0; i--) {
        result.push_back(addNum + tmp[i]);
    }
    return result;
}
int main() {
    int n;
    while (cin >> n) {
        vector<int> res = grayCode(n);
        for (auto c : res) {
            cout << c << " ";
        }
        cout << "\n***********************************\n";
    }

    return 0;
}

