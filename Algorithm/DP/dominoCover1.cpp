//
// Created by BranY on 2016/7/24.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/problemset/problem/1143

#include <iostream>
using namespace std;
/**
 * 我们有一个2xN的长条形棋盘，然后用1x2的骨牌去覆盖整个棋盘。对于这个棋盘，一共有多少种不同的覆盖方法
 * F[0] = 1, F[1] = 1, F[2] = 2, F[3] = 3
 * F[n] = F[n-1] + F[n-2]
 * 我们希望找到一个2x2的矩阵M，使得(a, b) x M = (b, a+b)，其中(a, b)和(b, a+b)都是1x2的矩阵。只需要取M = [0, 1; 1, 1]
 *
 * (fn-2, fn-1) * (0, 1 : 1, 1) = (fn-1, fn)
 * (0, 1) * M * M ....*M = (fn-1, fn) (n个M)
 *
 * [f(n), f(n-1) : f(n-1), f(n-2)] = [1, 1, 1, 0] ^ (n-1)
 *
 * left : [F(n+1), F(n) : F(n), F(n-1)]
 * right: [1,1:1,0]^n
 *
 * A^n = A^(n/2) * A^(n/2)               n%2==0
 *       A^((n-1)/2) * A^((n-1)/2) * A   n%2!=0
 *
 * 1. 先计算出所有的{a^1, a^2, a^4 ... a^(2^j)}，因为该数列满足递推公式，时间复杂度为O(logN)
 * 2. 将指数n二进制化，再利用公式将对应的a^j相乘计算出a^n，时间复杂度仍然为O(logN)
 *    则总的时间复杂度为O(logN)
 */
typedef long long ll;
const int mod = 19999997;
int N;//宽度是2， N <= 100,000,000
struct Matrix {
    ll map[2][2];
}ans, base;
Matrix unit = {1, 0, 0, 1};

ll finobacci_no_recursive(int n) {
    if (n == 0)
        return 0;
    if (n == 1) return 1;
    ll first = 0;
    ll second = 1;
    ll fib = 0;
    unsigned int current = 1;
    while (current <= n) {
        fib = (first + second) % mod;
        first = second % mod;
        second = fib % mod;
        ++current;
    }
    return fib;
}
Matrix matirx_Fibobacci(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            c.map[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c.map[i][j] += (a.map[i][k] * b.map[k][j]) % mod;
            c.map[i][j] %= mod;
        }
    return c;
}
ll pow(ll n) {
    base.map[0][0] = base.map[0][1] = base.map[1][0]=1;
    base.map[1][1] = 0;
    ans.map[0][0] = ans.map[1][1] = 1;
    ans.map[1][0] = ans.map[0][1] = 0;
    while (n) {
        if (n & 1) ans = matirx_Fibobacci(ans, base);
        base = matirx_Fibobacci(base, base);
        n >>= 1;
    }
    return ans.map[0][1] % mod;
}
int main() {
    while (cin >> N) {
        cout << pow(N+1) % mod << " " << finobacci_no_recursive(N) % mod << endl;
    }
    return 0;
}
//62247088
//17748018