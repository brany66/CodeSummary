//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>

using namespace std;
void dfs(const string &digits, int index, string &tmp, vector<string>&res) {
    string numap[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    if (index == digits.size()){
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < numap[digits[index] - '0'].size(); i++) {
        tmp[index] = numap[digits[index] - '0'][i];
        dfs(digits, index + 1, tmp, res);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.size() == 0)
        return res;
    string tmp(digits.size(), ' ');
    dfs(digits, 0, tmp, res);
    return res;
}

int main()
{
    string test = "23";
    vector<string> res = letterCombinations(test);
    for (auto c : res)
        cout << c << endl;
    return 0;
}