//
// Created by BranY on 2016/7/23.
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// Contact at wyang@smail.nju.edu.cn
//

#include <iostream>
#include <string.h>
using namespace std;
int dp[100][100];
/**
 * 20个桶，每个桶中有10条鱼，用网从每个桶中抓鱼，每次可以抓住的条数随机，每个桶只能抓一次，问一共抓到180条的排列有多少种
 * 1. 每个桶可以抓[0,10], 若在桶T0 ~ Ti抓取的鱼为k(0 <= k <= 10 * i), 则抓到180条的排列为剩下的20-i桶中抓取180-k的排列
 * 2. 抓取180条之后，20个桶中剩余20条鱼 ==> 将20条鱼分到20个桶中有多少中不同的排列方法
 */
int catchFish(int n, int m) {
    if (n == 0 && m == 0)
        return 1;
    if (n == 0 || m < 0)
        return 0;
    if (dp[n][m] == 0) {
        for (int i = 0; i <= 10; i++) {
            dp[n][m] += catchFish(n - 1, m -i);
        }
    }
    return dp[n][m];
}
/**
 * 一个桶装鱼，装0-10条鱼都是合法的，其余的就不合法了
 * dp[i][j]前i个桶中放j条鱼的方法 ： 前i-1个桶放j-k（0<=k<=10）条鱼的方法总和
 * dp[i][j] = Sum(dp[i-1][j-k]) 0 <= k <=10
 */
int catchFish_dp(int n, int m) {
    int dp1[100][100];
    memset(dp1, 0, sizeof(dp1));
    for (int i = 0; i <= 10; i++) dp1[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <=10 && j-k >= 0; ++k)
                dp1[i][j] += dp1[i-1][j-k];
        }
    }
    return dp1[n][m];
}

int catchFish_dp2(int n, int m) {
    int dp1[100][100];
    dp1[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <=10 && j-k >= 0; ++k)
                dp1[i][j] += dp1[i-1][j-k];
        }
    }
    return dp1[n][m];
}
int main() {
    int bucketNum, fishNum;
    while (cin >> bucketNum >> fishNum) {
        memset(dp, 0, sizeof(dp));
        //cout << catchFish(bucketNum, fishNum) << endl;
        cout << catchFish_dp(bucketNum, fishNum) << endl;
        //cout << catchFish_dp2(bucketNum, fishNum) << endl;
    }
    return 0;
}