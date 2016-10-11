//
// Created by BranY on 2016/9/17.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/contest/ntest2016spring2/problem/3
// http://46aae4d1e2371e4aa769798941cef698.devproxy.yunshipei.com/loststephon/article/details/51223557
// http://agatelee.cn/2016/04/%E6%95%B0%E4%BD%8Ddp/

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

bool cal(ll num) {

    bool flag = false;
    if(num % 7 != 0) return false;
    while(num > 0) {
        int temp1 = num % 10;
        int temp2 = num % 100;
        if(temp2 == 18)return false;
        if(temp1 == 2 || temp1 == 3 || temp1 == 5 )flag = true;
        num = num / 10;
    }
    if(!flag)return false;
    return true;
}

int process(const int N, const int M) {
    ll res = 0;
    ll i = N;
    for(; i <= M; i++) {
        if(cal(i)) {
            res++;
            break;
        }
    }
    ll j = i;
    for(; j <= M; j += 7) {
        if(cal(j))
            res++;
    }
}
int dp[20][2][2][7];
int digit[20];

ll dfs(int len,bool state, int has, int sum, bool fp) {
    if(!len) {
        if(has == 1 && sum == 0) {
            return 1;
        }
        else return 0;
    }

    if(!fp && dp[len][state][has][sum] != -1) {
        return dp[len][state][has][sum];
    }

    ll ret = 0 , fpmax = fp ? digit[len] : 9;
    for(int i = 0; i <= fpmax; i++) {
        // 不含18
        if(state && i == 8)
            continue;

        //含有2，3，5
        int prehas = has;
        int presum = sum;
        sum *= 10;
        sum += i;
        sum %= 7;

        if(!has && (i == 2 || i == 3 || i == 5))
        {
            has = 1;
        }

        ret += dfs(len - 1,i == 1, has, sum, fp && i == fpmax);
        has = prehas;
        sum = presum;
    }

    if(!fp) {
        dp[len][state][has][sum] = ret;
    }

    return ret;
}
ll f(long long n) {
    ll len = 0;
    while(n) {
        digit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len, false, 0, 0, true);
}
int main() {
    int S;
    ll N,M;
    while (cin >> S) {
        while(S--) {
            cin >> N >> M;
            //ll res = process(N, M);
            //cout << res << endl;
            memset(dp, -1, sizeof(dp));
            cout << (f(M) - f(N - 1)) << endl;
        }
    }
    return 0;
}
