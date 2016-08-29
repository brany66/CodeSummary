//
// Created by BranY on 2016/8/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/**
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Different from the previous question where weight is increasing from root to leaf,
 * now the weight is defined from bottom up. i.e.,
 * the leaf level integers have weight 1, and the root level integers have the largest weight.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
 * Example 2:
 * Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
 */
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
void helper(NestedInteger ni, int depth, vector<int> &v) {
    if (depth >= v.size()) v.resize(depth + 1);
    if (ni.isInteger()) {
        v[depth] += ni.getInteger();
    } else {
        for (auto a : ni.getList()) {
            helper(a, depth + 1, v);
        }
    }
}
int depthSumInverse(vector<NestedInteger>& nestedList) {
    int res = 0;
    vector<int> v;
    for (auto a: nestedList) {
        helper(a, 0, v);
    }
    for (int i = v.size() - 1; i >= 0; i++) {
        res += v[i] * (v.size() - i);
    }
}

/**
 * 用两个变量unweighted和weighted，非权重和跟权重和，初始化均为0，
 * 然后如果nestedList不为空开始循环，先声明一个空数组nextLevel，
 * 遍历nestedList中的元素，如果是数字，则非权重和加上这个数字，
 * 如果是数组，就加入nextLevel，这样遍历完成后，第一层的数字和保存在非权重和unweighted中了，
 * 其余元素都存入了nextLevel中，此时我们将unweighted加到weighted中，将nextLevel赋给nestedList，
 * 这样再进入下一层计算，由于上一层的值还在unweighted中，所以第二层计算完将unweighted加入weighted中时，
 * 相当于第一层的数字和被加了两次
 * @return
 */

int depthSumInverse_2(vector<NestedInteger>& nestedList) {
    int unweighted = 0, weighted = 0;
    while (!nestedList.empty()) {
        vector<NestedInteger> nextLevel;
        for (auto a : nestedList) {
            if (a.isInteger()) {
                unweighted += a.getInteger();
            } else {
                nextLevel.insert(nextLevel.end(), a.getList().begin(), a.getList().end());
            }
        }
        weighted += unweighted;
        nestedList = nextLevel;
    }
    return weighted;
}
int main() {
    return 0;
}
