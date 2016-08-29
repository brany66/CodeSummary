//
// Created by BranY on 2016/8/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//
/**
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
 * Example 2:
 * Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
 */
#include <iostream>
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
int help(const vector<NestedInteger> &a, int level) {
    int res = 0;
    for (auto c : a) {
        res += c.isInteger() ? c.getInteger() * level : help(c.getList(), level + 1);
    }
    return res;
}
int depthSum(vector<NestedInteger> &nestedList) {

    return help(nestedList, 1);
}


int getSum(NestedInteger ni, int level) {
    int res = 0;
    if (ni.isInteger()) return level * ni.getInteger();
    for (auto a : ni.getList()) {
        res += getSum(a, level + 1);
    }
    return res;
}
int depthSum_1(vector<NestedInteger>& nestedList) {
    int res = 0;
    for (auto a : nestedList) {
        res += getSum(a, 1);
    }
    return res;
}

int main() {
    return 0;
}
