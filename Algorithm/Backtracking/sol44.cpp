//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/wildcard-matching/
// Similar with Sol_10

#include <iostream>
#include <vector>
using namespace std;
bool isMatch(string s, string p) {
    if (p.size() == 0)
        return s.size() == 0;
    if (s.size() > 300 && p[0] == '*' && p[p.size() - 1] == '*') return false;
    vector<bool> res(s.size() + 1, false);
    res[0] = true;
    for (int j = 0;  j < p.size(); ++j) {
        if (p[j] != '*') {
            for (int i = s.size() - 1; i >=0; --i)
                res[i+1] = res[i] && (p[j] == '?' || s[i] == p[j]);
        } else {
            int i = 0;
            while (i <= s.size() && !res[i]) i++;
            while (i <= s.size()) res[i++] = true;
        }
        res[0] = res[0] && p[j] == '*';
    }
    return res[s.size()];
}
int main()
{
    vector<string> test{"aa","aa", "aaaa", "aa", "aa", "ab", "aab"};
    vector<string> rule{"a", "aa", "aa", "*", "a*", "?*", "c*a*b"};
    for (int i = 0; i < test.size(); i++) {
        if (isMatch(test[i], rule[i]))
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}