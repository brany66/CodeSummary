//
// Created by BranY on 2016/7/24.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/problemset/problem/1151

#include <iostream>
#include <signal.h>

#include <vector>
using namespace std;
/**
 * 我们有一个3xN的长条形棋盘，然后用1x2的骨牌去覆盖整个棋盘。对于这个棋盘，一共有多少种不同的覆盖方法
 *
 * 每一种放置方法解释如下，假设当第i行的状态为x，第i-1行的状态为y：
 * 第i行不放置，则前一行必须有放置的骨牌。x对应二进制位为0，y对应二进制位为1。
 * 第i行竖放骨牌，则前一行必须为空。x对应二进制位为1，y对应二进制位为0。
 * 第i行横向骨牌，则前一行必须两个位置均有骨牌，否则会产生空位。x对应二进制位为1，y对应二进制位为1。
 * (0,0,0,0,0,0,0,1)
 * 其实仔细想想画一画也可以得到递推公式，假设奇数的方案数不为0，只要有一个方块达到奇数长度，就算是其中一个方案，那么有：
 * a[0] = 0;    a[1] = 2;     a[2] = 3;
 * 对于奇数：a[i] = 2 * a[i-1] + a[i-2];  对于偶数：a[i] = 3*a[i-2] + a[i-3];
 */
typedef long long ll;
const int mod = 12357;
int N;//宽度是2， N <= 100,000,000
const int state = 8;
ll a[5];
struct Matrix {
    int m, n;
    vector<vector<ll> > a;
    Matrix (int m, int n) : m(m), n(n) {
            a = vector<vector<ll> >(m, vector<ll>(n));
    }
    Matrix(int m, int n, ll *b) : m(m), n(n) {
        a = vector<vector<ll> >(m, vector<ll>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = b[i*n+j];
            }
        }
    }

    void operator*=(const Matrix &r) {
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
void dominoCover_2() {
    a[0] = 0;
    a[1] = 2;
    a[2] = 3;
    for (int i = 3 ; i <= N; i++) {
        if (i & 1)
            a[i%5] = (2 * a[(i-1+5)%5] + a[(i-2+5)%5]) % mod;
        else
            a[i%5] = (3 * a[(i-2+5)%5] + a[(i-3+5)%5]) % mod;
    }
    cout << a[N%5] << endl;
}

int main() {
    ll b[] = {
            0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 1,
            0, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0, 0, 1,
            1, 0, 0, 1, 0, 0, 1, 0,
    };
    Matrix m(state, state, b);
    while (cin >> N) {
        if (N & 1) cout << "0" << endl;
        else {
            dominoCover_2();
            Matrix A(1, 8, b);
            for (int t = 0; t < 32; t++) {
                if (N & (1 << t)) A *= m;
                m *= m;
            }
            cout << A.a.back().back() << endl;
        }
    }
    return 0;
}
//62247088
//4037