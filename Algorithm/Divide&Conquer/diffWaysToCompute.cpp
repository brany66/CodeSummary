//
// Created by BranY on 2016/8/25.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1));

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    if (input[i] == '+')
                        res.push_back(left[j] + right[k]);
                    else if (input[i] == '-')
                        res.push_back(left[j] - right[k]);
                    else
                        res.push_back(left[j] * right[k]);
                }
            }
        }
    }
    if (res.empty())
        res.push_back(atoi(input.c_str()));
    return res;
}
int main() {
    string str;
    while (getline(cin, str)) {
        vector<int> res = diffWaysToCompute(str);
        for (auto c : res)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
