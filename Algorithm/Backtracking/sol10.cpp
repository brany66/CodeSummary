//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <vector>

using namespace std;
bool dfs(string s, string p, int i, int j) {
    if (j == p.size())
        return i == s.size();
    if (j == p.size() - 1 || p[j+1] != '*') {
        if(i == s.length() || s[i] != p[j] && p[j] != '.')
            return false;
        else
            return dfs(s, p, i + 1, j + 1);
    }
    while (i < s.size() && (p[j] == '.' || s[i] == p[j])) {
        if (dfs(s, p, i, j+2))
            return true;
        i++;
    }
    return dfs(s, p, i, j+2);
}
bool isMatch(string s, string p) {
    return dfs(s, p, 0, 0);
}
int main()
{
    vector<string> test{"aa","aa", "aaaa", "aa", "aa", "ab", "aab"};
    vector<string> rule{"a", "aa", "aa", "a*", ".*", ".*", "c*a*b"};
    for (int i = 0; i < test.size(); i++) {
        if (isMatch(test[i], rule[i]))
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}

