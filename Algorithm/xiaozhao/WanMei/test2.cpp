//
// Created by BranY on 2016/9/19.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE =105;

int dp[SIZE][SIZE];
int main() {
    int n;
    while (cin >> n) {
        vector<int> res(SIZE, 0);
        for(int i=1;i<=n;++i) {
           cin >> res[i];
            dp[i][i] = res[i];
            res[i] += res[i-1];
        }
        for(int i = 1;i < n; ++i) {
            for(int j = i+1; j <= n; ++j) {
                dp[j-i][j] = max(res[j] - res[j-i-1] - dp[j-i+1][j],
                               res[j] - res[j-i-1] - dp[j-i][j-1]);
            }
        }
        cout << dp[1][n] << " " << res[n] - dp[1][n]  << endl;
    }
    return 0;
}
