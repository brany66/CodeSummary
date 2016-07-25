//
// Created by BranY on 2016/7/23.
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// Contact at wyang@smail.nju.edu.cn
//

#include <iostream>
#include <vector>
using namespace std;
/**
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * s[i,j] = 0				if j==0
 *          j				if i==0
 *          min{s[i-1,j], s[i,j-coins[i]] + 1}	if i,j != 0
 */
int coin_change_dp(vector<int>& coins, int cents) {
    vector<vector<int>> s(coins.size(), vector<int>(cents+1));
    for (int j = 0; j < s[0].size(); j++) {
        if (j%coins[0] == 0) {
            s[0][j] = j/coins[0];
        } else {
            s[0][j] = -1;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        s[i][0] = 0;
    }
    for (int i = 1; i < s.size(); i++) {
        for (int j = 1; j < s[i].size(); j++) {
            int v1 = s[i-1][j];
            int v2 = -1;

            if (j -coins[i] >= 0 && s[i][j-coins[i]] >= 0) {
                v2 = s[i][j-coins[i]] + 1;
            }

            if (v1 < 0 && v2 < 0) {
                s[i][j] = -1;
            } else if (v1 >= 0 && (v2 < 0 || v1 < v2)) {
                s[i][j] = v1;
            } else {
                s[i][j] = v2;
            }
        }
    }

    if (s[coins.size()-1][cents] < 0) {
       cout << "Cannot change coins" << endl;
    }
    cout << s[coins.size()-1][cents] << endl;
}
int coinChange(vector<int>& coins, int amount) {
    const int INF = 0x7fffffff;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int i = 0; i <= amount; i++) {
        for (int j = 0; j<coins.size(); j++) {
            if (i + coins[j] <= amount && dp[i]!= INF && dp[i + coins[j]] > dp[i] + 1)
                dp[i + coins[j]] =dp[i] + 1;
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}
int main() {
    vector<int> coins1{5, 8, 1}, coins2{13, 1, 10, 7}, coins3{1, 25,10, 5}, coins4{3, 5};
    int cents1 = 10, cents2 = 152, cents3 = 92, cents4 = 22;

    cout << coinChange(coins1, cents1) << " " << coinChange(coins2, cents2) << " " << coinChange(coins3, cents3)
            << " " << coinChange(coins4, cents4) << endl;
    coin_change_dp(coins1, cents1);
    coin_change_dp(coins2, cents2);
    coin_change_dp(coins3, cents3);
    coin_change_dp(coins4, cents4);
    return 0;
}