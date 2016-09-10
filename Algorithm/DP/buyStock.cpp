//
// Created by BranY on 2016/9/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

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

//
int main() {
    //vector<int> res = {7,1,5,3,6,4};
    vector<int> res = {7,6,4,3,1};
    cout << maxProfit(res) << endl;
    return 0;
}
