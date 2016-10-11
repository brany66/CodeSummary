//
// Created by BranY on 2016/10/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100005;
const int M = 205;
char str[N];
int ind[30][30];
int dp[30];

int main() {
    int n, m;
    while (cin >> n) {
        scanf("%s", str);
        scanf("%d", &m);
        memset(ind, 0, sizeof(ind));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<m; i++) {
            char a,b;
            getchar();
            scanf("%c%c", &a, &b);
            ind[a-'a'][b-'a'] = ind[b-'a'][a-'a'] = 1;
        }
        for(int i=0; i<strlen(str); i++)
        {
            char a = str[i];
            int tmp = 1;
            for(int j=0; j<26; j++)
            {
                if(ind[a-'a'][j]) continue;
                tmp = max(tmp,dp[j]+1);
            }
            dp[a-'a'] = tmp;
        }
        sort(dp, dp+26);
        printf("%d\n", n - dp[25]);
    }
    return 0;
}
