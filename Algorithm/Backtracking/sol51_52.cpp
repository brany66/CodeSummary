//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/n-queens/
// https://leetcode.com/problems/n-queens-ii/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//行，列，对角线
/**
 * 在每一层递归函数中，我们用一个循环把一个皇后填入对应行的某一列中，如果当前棋盘合法，我们就递归处理先一行，找到正确的棋盘我们就存储到结果集里面。
 * 用一个循环去枚举当前所有情况，然后把元素加入，递归，再把元素移除，这道题目中不用移除的原因是我们用一个一维数组去存皇后在对应行的哪一列，
 * 因为一行只能有一个皇后，如果二维数组，那么就需要把那一行那一列在递归结束后设回没有皇后
 * 检查当前棋盘合法性，因为除了刚加进来的那个皇后，前面都是合法的，只需要检查当前行和前面行是否冲突即可。检查是否同列很简单，检查对角线就是行的差和列的差的绝对值不要相等就可以。
 */
bool check(int row, vector<int> columnForRow) {
    for (int i = 0; i < row; i++) {
        if (columnForRow[row] == columnForRow[i] || abs(columnForRow[row] - columnForRow[i]) == abs(row - i))
            return false;
    }
    return true;
}
void dfs(vector<vector<string>> &res, vector<int> &tmp, int index, const int n) {
    if (index == n) {
        vector<string> ls(n, "");
        for(int i = 0;i < n;i++) {
            string s;
            for(int j = 0;j < n;j++)
            {
                if(tmp[i] == j)
                    s.push_back('Q');
                else
                    s.push_back('.');
            }
           ls[i] = s;
        }
        res.push_back(ls);
        return;
    }
    for (int i = 0; i < n; i++) {
        tmp[index] = i;
        if (check(index, tmp))
            dfs(res, tmp, index+1, n);
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    if (n < 1) return res;
    vector<int> tmp(n, 0);
    dfs(res, tmp, 0, n);
    return res;
}
int main() {
    vector<vector<string>> res = solveNQueens(4);
    for (auto list : res) {
        for (auto a : list)
            cout << a << endl;
        cout << "***********************\n";
    }
    return 0;
}

