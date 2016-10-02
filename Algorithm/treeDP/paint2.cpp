//
// Created by BranY on 2016/10/1.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
/**
 * 定义状态dp[u][m]表示以根节点u开始选出m个点连通的最大总权值，则：
 * dp[u][m] = max(dp[u][m], dp[u][m-k]+dp[son][k])
 * 其中k->[0, m]
 */
using namespace std;
const int N = 1000;
const int INF = 1000000000;
const double inf = 1e20;

int n, m;
int w[105];
vector<int> e[105];
int dp[105][105];
void dfs(int u, int fa) {
    fill(dp[u], dp[u] + m + 1, w[u]);
    dp[u][0] = 0;
    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (v == fa) continue;
        dfs(v, u);
        for (int j = m; j >=2; --j) {
            for (int k = j-1; k >=0; --k)
                dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[v][k]);
        }
    }
}
int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            e[i].clear();
        }
        int a, b;
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            --a, --b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs(0, -1);
        cout << dp[0][m] << endl;
    }
    return 0;
}
