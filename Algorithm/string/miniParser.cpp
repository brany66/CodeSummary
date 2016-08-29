//
// Created by BranY on 2016/8/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
using namespace std;
class NestedInteger {
public :
    NestedInteger();
    NestedInteger(int value);
    bool isInteger() const;
    int getInteger() const;
    void setInteger(int value);
    void add(const NestedInteger &ni);
    const vector<NestedInteger> &getList() const;

};
stack<int>  num;
NestedInteger deserialize(string s) {
    if (s.empty()) return NestedInteger();
    if (s[0] != '[') return NestedInteger(atoi(s.c_str()));
    if (s.size() <= 2) return NestedInteger();
    //stack<NestedInteger> st;
    NestedInteger res;
    int start = 1, cnt = 0;
    for (int i = 1; i < s.size(); i++) {
        if (cnt == 0 && (s[i] == ',' || i == s.size() - 1)) {
            res.add(deserialize(s.substr(start, i - start)));
            start = i + 1;
        } else if (s[i] == '[') ++cnt;
        else if (s[i] == ']') --cnt;
    }
}

int main() {
    return 0;
}
