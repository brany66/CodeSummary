//
// Created by BranY on 2016/9/13.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <cstdlib>
#include <iostream>
#define M 105
#define V 10005
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    int T;
    cin >>T;
    while(T--){
        int n, bot, top, ans=0;
        cin >> n >> bot >> top;
        while(n--){
            int m, c, v, dp[V] = {0};
            for(int j = 0; j <= top; j++)
                dp[j] = -INF;
            dp[0] = 0;

            cin >> m;
            for(int i = 0; i < m; i++){
                cin >> c >>v;
                for(int j = top; j >= c; j--)
                    dp[j] = max(dp[j], dp[j-c] + v);
            }

            for(int j=bot; j<=top; j++)
                ans = max(ans, dp[j]);

        }
        cout <<ans <<endl;
    }
    return 0;
}