//
// Created by BranY on 2016/9/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int MIN = prices[0], res = 0;
    for (int i = 1; i < prices.size(); i++){
        if (MIN > prices[i]) MIN = prices[i];
        else {
            res = max(res, prices[i] - MIN);
        }
    }
    return res;
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
int maxProfit_2(vector<int>& prices) {
    int ret = 0;
    for (size_t p = 1; p < prices.size(); ++p)
        ret += max(prices[p] - prices[p - 1], 0);
    return ret;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
int maxProfit_3(vector<int>& prices) {
    int res = 0;
    if (prices.size() <= 1) return res;
    int prev1 = INT_MIN, prev2 = INT_MIN, cur = 0;
    for (auto c : prices) {
        res = max(res, prev2 + c);
        prev2 = max(prev2, cur - c);
        cur = max(cur, prev1 + c);
        prev1 = max(prev1, -c);
    }
    return res;
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
int maxProfit(int k, vector<int>& prices) {
    if (k >= prices.size() - 1) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }

    //vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
    int buy = INT_MIN, sell = 0;
    for (int p : prices) {
        for (int i = 1; i <= k; i++) {
            buy = max(buy, sell - p);
            sell = max(sell, buy + p);
            //buy[i] = max(buy[i], sell[i - 1] - p);
            //sell[i] = max(sell[i], buy[i] + p);
        }
    }
    return sell;
}
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
int maxProfit_4(vector<int>& prices) {
    vector<int> s{0, INT_MIN, 0};
    for (int c : prices)
        s = { max(s[0], s[2]), max(s[0] - c, s[1]), s[1] + c};
    return max(s[0], s[2]);
}
int main() {
    int a =1,b =32 ;
    printf("%d,%d\n",a<<b,1<<32);
    vector<int> res = {7,1,5,3,6,4};
    //vector<int> res = {7,6,4,3,1};
    cout << maxProfit_3(res) << endl;
    return 0;
}
