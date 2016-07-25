//
// Created by BranY on 2016/7/24.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/problemset/problem/1162

#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
/**
 * 我们有一个KxN的长条形棋盘，然后用1x2的骨牌去覆盖整个棋盘。对于这个棋盘，一共有多少种不同的覆盖方法
 * 第i行不放置，则前一行必须有放置的骨牌。x对应二进制位为0，y对应二进制位为1。
 * 第i行竖放骨牌，则前一行必须为空。x对应二进制位为1，y对应二进制位为0。
 * 第i行横向骨牌，则前一行必须两个位置均有骨牌，否则会产生空位。x对应二进制位为1，y对应二进制位为1。
 *
 * 既然有对应的二进制描述，那么上面三种方法就可以用程序语言解释为:
 * 第i行不放置：new_x = x << 1, new_y = (y << 1) + 1; 列数+1
 * 第i行竖放骨牌：new_x = (x << 1) + 1, new_y = y << 1; 列数+1
 * 第i行横向骨牌：new x = (x << 2) + 3, new_y = (y << 2) + 3; 列数+2
 *
 * 我们可以以状态x=0, y=0开始，从第1列开始枚举，每一列都同时枚举以上三种覆盖方式，当枚举到最后一列时，则表示可以从此时的x转移到y。
 */
typedef long long ll;
const int mod = 12357;
int K, N;//K ->[2,7] ， N <= 100,000,000
struct Matrix {
    int m, n;
    vector<vector<ll> > a;
    Matrix (int m, int n) : m(m), n(n) {
        a = vector<vector<ll>> (m, vector<ll>(n));
    }
    Matrix(int m, int n, ll *b) : m(m), n(n) {
        a = vector<vector<ll>>(m, vector<ll>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = b[i*n+j];
            }
        }
    }

    void operator  *= (const Matrix &r) {
        Matrix res(m, r.n);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < r.n; col++) {
                for (int k = 0; k < n; k++) {
                    res.a[row][col] += a[row][k] * r.a[k][col];
                    res.a[row][col] %= mod;
                }
            }
        }
        *this = res;
    }
};
// 进入此函数时第i-1列状态为x，第i列状态为y
void dfs(int x, int y, int col, vector<vector<ll> > &d) {
    if (col == K) {
        d[x][y] = 1;
        return;
    }
    dfs(x | (1 << col), y, col + 1, d); //不放置
    dfs(x, y | (1 << col), col + 1, d); //横向放置
    if (col + 2 <= K)
        dfs(3 | (3 << col), y | (3 << col), col + 2, d); // 竖向放置


}
void getTransferMatrix(vector<vector<ll> > &d) {
    dfs(0, 0, 0, d);
}
int main() {
    while (cin >> K >> N) {
        Matrix state(1<<K, 1<<K);
        getTransferMatrix(state.a);
        Matrix A(1, 1<<K);
        *(A.a.back().rbegin()) = 1;
        for (int t = 0; t < 32; t++){
            if (N & (1 << t)) A *= state;
            state *= state;
        }
        cout << A.a.back().back() << endl;
    }
    return 0;
}