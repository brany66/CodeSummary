//
// Created by BranY on 2016/8/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
/**
 * Range Minimum Query
 * 大意就是，有一个数列 {a1,a2,a3,a4,a5,a6,a7.......an} ，在其中连续的区间内，算出该区间内最大最小值的差。
 * 示范数据：9  2 5  1  10 7  3  21 8  15  4 22  19  6
 *
 * f[i][j]代表从i开始长度为2^{j}的一段区间(即[i,i+2^{j}-1])中最大/小的值
 * f[i][j] = Max{f[i][j-1], f[i+2^(j-1)][j-1] }
 */
using namespace std;
int f[1000][20];
int min[1000][20];
int N, M;//N:区间大小 M:数据个数
void build(); //ST算法
inline int get(int b, int e); //取得最大值
inline void set(int x, int y); //将y放置在x处并更新
int main() {
    int i, b, e, p;
    cin >> N;
    for (i = 1; i <= N; i++)
        cin >> f[i][0];
    build();
    cin >> M;
    int c;
    for (i=1;i<=M;i++) {
        cin >> c;
        if (c==1){//修改
            cin >> b >> p;
            set(b,p);
        }
        else {//查询
            cin >> b >> e;
            cout << get(b,e)<< endl;
        }
    }
    return 0;
}
void build() {
    int i, j;
    for (j = 1; (1 << j) <= N; j++)
        for (i = 1; i+(1 << j) - 1 <= N; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
}