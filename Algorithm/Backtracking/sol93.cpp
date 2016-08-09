//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/restore-ip-addresses/

#include <iostream>
//#include <string.h>
#include <vector>
#include <cstdlib>

using namespace std;
void dfs(const string &s, vector<string> &res, string &tmp, int index, int count) {
    if (count == 4 && index == s.size()){
        res.push_back(tmp);
        return;
    }

    for (int i = 1; i < 4; i++) {
        if (index + i > s.size()) break;
        string ret = s.substr(index, i);
        //cout << "ret " << ret <<  " " << atoi(ret.c_str()) << endl;
        if ((ret[0] == '0' && ret.size() > 1) || (i == 3 && atoi(ret.c_str()) >= 256)) continue;
        string A = (tmp + ret + (count == 3 ? "" : "."));
        dfs(s, res, A, index+i, count+1);
    }
}
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if (s.size() < 4 || s.size() > 12) return res;
    string tmp = "";
    dfs(s, res, tmp, 0, 0);
    return res;
}


int main()
{
    string test="25525511135";

    vector<string> res = restoreIpAddresses(test);
    for (auto c : res)
        cout << c << endl;
    return 0;
}

