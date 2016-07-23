//
// Created by wuyan on 2016/7/16.
// Contact mail wyang@smail.nju.edu.cn
//
#include <iostream>
#include <string.h>

using namespace std;
int dp[502][100002];
int dp1[100005];
int need[502], value[502];
int N, M;
void dfs1() {
    int i , j;
    for (i =  1; i <= N; i++)
        for (j = 0; j <= M; j++) {
            if (j < need[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - need[i]] + value[i]);
        }
}
void dfs2() {
    memset(dp1, 0, sizeof(dp1));
    for (int i = 1; i <= N; i++)
        for (int j = M; j >= need[i]; j--)
            dp1[j] = max(dp1[j], dp1[j - need[i]] + value[i]);
}
int main()
{
    while (cin >> N >> M) {
        int i, j;
        for (i = 1; i <= N; i++)
            cin >> need[i] >> value[i];
        for (j = 0; j <= M; j++) dp[0][j] = 0;
        dfs2();
        cout << dp1[M] << endl;
        //cout << dp[N][M];
    }
    return 0;
}
