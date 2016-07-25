//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/problemset/problem/1048

#include <iostream>
#include <string.h>
using namespace std;
const int mod = 1000000007;
int N, M; // n<-[2,1000], m[3,5]
int dp[1005][1025];
/**
 * 小Hi和小Ho领到了一个大小为N*M的长方形盘子，他们可以用这个盒子来装一些大小为2*1的蛋糕
 * 但是根据要求，他们一定要将这个盘子装的满满的，一点缝隙也不能留下来，才能够将这些蛋糕带走。
 *
 * 既然无论以什么样的排列顺序都会致使同样的结果，那么我们就想办法给它定义一个顺序便是了呢？
 * 比如说，对于每一块蛋糕，以其左（上）边一块的行号为第一关键字，列号为第二关键字的顺序，只有按照这个顺序递增的排列才是合法的！
 *
 * 行为第一关键字，列为第二关键字
 *
 * 1. 若N=1,M%2==0,then 1*2的蛋糕可以覆盖1*M的盘子
 * 2. 若N, M都为奇数，则不能完全覆盖
 *
 * 令sum(i, j, p1, p2, ... , pM, q1, q2, ... , qM)表示：已经将第一行至第i-1行的盘子都已经填满了
 * 当前正在尝试往(i, j)这个位置放置蛋糕，而第i行的放置情况用p1...pM表示，第i+1行的放置情况用q1...qM表示——0表示为空，1表示放置了蛋糕。
 * 那么sum(i, j, p1, p2, ... , pM, q1, q2, ... , qM)便表示在这种情况下，剩余的格子有多少种填充的方法，而我们要求的问题便是sum(1, 1, 0, 0, 0, ..., 0)
 *
 * sum(i, j, p1, p2, ... , pM, q1, q2, ... , qM) =
 *                  sum(i,j+1,p1, p2, ... , pM, q1, q2, ... , qM)        if pj = 1, j < M
 *                  sum(i+1,j,q1, q2, ... , qM, 0,0,....,0)              if pj = 1, j = M
 *                  0                                                    if pj = 0, j = M V pj+1 = 1, i=N || qj = 1
 *                  sum(i,j,p1, p2, .pj=1.. , pM, q1, q2, ... , qM)      if pj = 0, j < M && pj+1 = 0, i = N || qj = 1
 *                  sum(i,j,p1, p2, .pj=1.. , pM, q1, q2, ..qj=1. , qM)  if pj = 0, j = M && pj+1 = 1, i < N || qj = 0
 *                  sum(i,j,p1, p2, .pj=1.. , pM, q1, q2, ... , qM)+ sum(i,j,p1, p2, .pj=1.. , pM, q1, q2, ..qj=1. , qM) pj =0, j<M&&pj+1 = 0, i <N && qj=0
 */

void stateCompress_dp() {
    memset(dp, 0, sizeof(dp));
    int mx = (1 << M) - 1;
    int mxx = (1 << (1 << M));
    dp[0][0] = 1;
    for(int i = 0; i < N;++i) {
        for(int k = 0; k < M;++k)
            for(int j = 0; j < mxx; ++j)
                if(((1 << k) & j) == 0) {//当第k+1位没有蛋糕时，可以放下蛋糕
                    if(k != M-1 && ((1 << (k+1)) & j) == 0)//当k+1不是m位的状态时，且第k+2位没有蛋糕时，表示蛋糕可以横放
                        dp[i][j | (1<<k)| (1<<(k+1))] = (dp[i][j | (1<<k)| (1<<(k+1))] + dp[i][j]) % mod;
                    dp[i][j | (1<<(k+M)) | (1<<k)] = (dp[i][j | (1<<(k+M)) | (1<<k)] + dp[i][j]) % mod;//当第k+1位没有蛋糕时，必定可以竖放
                }
        for(int j = 0; j < mxx; ++j)//将第i行的状态转移至第i+1行
            if((j & mx) == mx)//如果第i行已被蛋糕放满，则该状态可以转移至下一行
                dp[i+1][j>>M] = dp[i][j];
    }
    cout << dp[N-1][mx] << endl;
}
int main()
{
    while (cin >> N >> M) {
        stateCompress_dp();
    }
    return 0;
}