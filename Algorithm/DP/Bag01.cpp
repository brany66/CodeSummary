//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/problemset/problem/1038

#include <iostream>
#include <string.h>
using namespace std;
int dp[502][100002];
int dp1[100005];
int need[502], value[502];
int N, M;
/**
 * 小Ho现在手上有M张奖券，而奖品区有N件奖品，分别标号为1到N，其中第i件奖品需要need(i)张奖券进行兑换，
 * 同时也只能兑换一次，为了使得辛苦得到的奖券不白白浪费，小Ho给每件奖品都评了分，其中第i件奖品的评分值为value(i),表示他对这件奖品的喜好值.
 * 现在他想知道，凭借他手上的这些奖券，可以换到哪些奖品，使得这些奖品的喜好值之和能够最大
 *
 * 以best(i, x)表示已经决定了前i件物品是否选取，当前已经选取的物品的所需奖券数总和不超过x时，能够获取的最高的喜好值的和.
 * 对于任意i>1, j，我们都可以知道best(i, j) = max{ best(i-1, j-need(i)) + value(i), best(i - 1, j)}
 */
void bag_dp() {
    int i , j;
    for (i =  1; i <= N; i++)
        for (j = 0; j <= M; j++) {
            if (j < need[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - need[i]] + value[i]);
        }
}

void bag_dp_2() {
    memset(dp1, 0, sizeof(dp1));
    for (int i = 1; i <= N; i++)
        for (int j = M; j >= need[i]; j--)
            dp1[j] = max(dp1[j], dp1[j - need[i]] + value[i]);
}
int main() {
    while (cin >> N >> M) {
        int i, j;
        for (i = 1; i <= N; i++)
            cin >> need[i] >> value[i];
        for (j = 0; j <= M; j++) dp[0][j] = 0;
        bag_dp();
        bag_dp_2();
        cout << dp1[M] << endl;
        cout << dp[N][M];
    }
    return 0;
}
/*
 *5 1000
144 990
487 436
210 673
567 58
1056 897
 */