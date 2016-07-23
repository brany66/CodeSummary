//
// Created by BranY on 2016/7/22.
// Contact at wyang@smail.nju.edu.cn
//
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
vector<int> p;
vector<vector<int>> m, s;
string out;
stringstream stream;
void reset() {
    m.resize(p.size() - 1, vector<int>(p.size() - 1));
    s.resize(p.size() - 1, vector<int>(p.size() - 1));
}
/**
 * n个矩阵构成的矩阵链相乘的问题
 * <A1, A2, A3, A4>
 * (A1(A2(A3A4)))、(A1,((A2,A3)A4))、((A1A2)(A3A4))、((A1(A2A3))A4)、(((A1A2)A3)A4)
 *
 * Ai的维度是pi-1, pi
 * 假设AiAi+1...Aj的一个最优加括号把乘积Ak, Ak+1分开
 * 1 <= i <= j <= n
 * m[i][j]为计算矩阵Ai..j的标量乘法的次数，最小代价m[1][n]
 * if i == j 区间内只有一个矩阵 m[i][i] = 0
 * if i < j, 其中i <= k < j,
 *           m[i][j] = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
 *
 * 自底向上求解
 */
int matrix_Chain_Order() {
    reset();
    int i, j, d;
    for (i = 0; i < m.size(); i++)
        m[i][i] = 0;
    for (d = 1; d < m.size(); d++) {
        for (i = 0; i+d < m.size(); i++) {
            j = i + d;
            int min = m[i][i] + m[i+1][j] + p[i]*p[i+1]*p[j+1];
            s[i][j] = i;
            for (int k = i+1; k < j; k++) {
                int v = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (min > v) {
                    min = v;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    return m[0][m.size() - 1];
}

string printOptimalParents(int i, int j) {
    stream.clear();
    if (i == j){
        string s = "A";
        string str;
        stream << i;

        stream >> str;
        s += str;
        return s;
    }
    int k = s[i][j];
    out = "(" + printOptimalParents(i, k) + printOptimalParents(k + 1, j) + ")";
    return out;
}
int main()
{
    p = {30, 35, 15, 5, 10, 20, 25};
    out = "";
    cout << matrix_Chain_Order() << endl;
    cout << printOptimalParents(0, m.size() - 1) << endl;

    out = "";
    p = {5, 10, 3, 13, 5, 50, 6};
    cout << matrix_Chain_Order() << endl;
    cout << printOptimalParents(0, m.size() - 1) << endl;
    return 0;
}
