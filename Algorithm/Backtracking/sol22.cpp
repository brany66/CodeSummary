//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/generate-parentheses/
#include <iostream>
#include <vector>

using namespace std;
void dfs(vector<string> &res, string tmp, int index, int n) {
   if (index == 0 && n == 0) {
       res.push_back(tmp);
       return;
   }
    if (index > 0) dfs(res, tmp+")", index-1, n);
    if (n > 0) dfs(res, tmp+"(", index+1, n-1);
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n <= 0) return res;
    string tmp ="";
    dfs(res, tmp, 0, n);
}
int main()
{
    vector<string> list = generateParenthesis(3);
    for (auto c: list)
        cout << c << endl;
    return 0;
}
