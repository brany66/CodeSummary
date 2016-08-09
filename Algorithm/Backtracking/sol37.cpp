//
// Created by BranY on 2016/8/8.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/sudoku-solver/

#include <iostream>
#include <vector>

using namespace std;
bool isValid(vector<vector<char>> &board, int i, int j) {
    //同一行中的重复数字
    for (int k = 0; k < 9; k++) {
        if (k != j && board[i][k] == board[i][j])
            return false;
    }
    //同一列中的重复数字
    for (int k = 0; k < 9; k++) {
        if (k != i && board[k][j] == board[i][j])
            return false;
    }
    //9格内
    for (int row = i/3 * 3; row < i/3 * 3 + 3; row++)
        for (int col = i/3 * 3; col < j/3 * 3 + 3; col++)
            if ((row != i || col != j) && board[row][col] == board[i][j]) return false;
    return true;
}
bool dfs(vector<vector<char>> &board, int i, int j) {
    if (j >= 9)
        return dfs(board, i+1, 0);
    if (i == 9) return true;
    if (board[i][j] == '.') {
        for(int k = 1; k <= 9; k++) {
            char c = '0';
            c += k;
            board[i][j] = c;
            if(isValid(board, i, j)) {
                if(dfs(board, i, j+1))
                    return true;
            }
            board[i][j] = '.';
        }
    } else {
        return dfs(board, i, j+1);
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board) {
    if (board.size() != 9 || board[0].size() != 9) return;
    dfs(board, 0, 0);
}
int main()
{
    char c = '1';
    c += 15;
    cout << c << endl;
    vector<vector<char>> solve = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(solve);
    for (auto c : solve) {
        for (auto b: c)
            cout << b << " ";
        cout << endl;
    }
    return 0;
}

