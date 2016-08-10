//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <vector>

using namespace std;
bool ishui(string s) {
    int i = 0, j = s.size()-1;
    while(i < j) {
        if(s[i] == s[j]) {
            i++;
            j--;
        }
        else return false;
    }
    return true;
}
void dfs(vector<vector<string>> &res, vector<string> &tmp, string s, int index) {
    if(index == s.size()){
        res.push_back(tmp);
        return;
    }
    if(index < s.size()) {
        for(int i = index; i < s.size(); i++){
            if(ishui(s.substr(index,i-index+1)))
            {
                tmp.push_back(s.substr(index,i-index+1));
                dfs(res, tmp, s,i+1);
                tmp.pop_back();
            }
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    if (s.size() == 0) return res;
    vector<string> tmp;
    dfs(res, tmp, s, 0);
    return res;
}

int main() {
    vector<vector<string>> list = partition("aab");

    for (auto a :list) {
        cout << "[";
        for (auto b: a) {
            cout << b << " " ;
        }
        cout << "]\n";
    }
    return 0;
}

