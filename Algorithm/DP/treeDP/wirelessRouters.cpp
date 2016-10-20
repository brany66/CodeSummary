//
// Created by BranY on 2016/10/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
struct Node {
    int to;
    int pa;
    Node(int a) : to(a) {}
   // Node(int a, int b) : to(a), pa(b) {}
};

const int N = 1005;
const int M = 105;
int dp[N][M][2];
int val[N];
vector<Node> edge[N];

int n, m;

void dfs(int u, int p) {

    for (int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i].to;
        if (v == p) continue;
        dfs(v, u);

        for (int j = m; j >= 1; --j) {
            for (int k = 1; k <= j; k++) {
                dp[u][j][0] = max(dp[u][j][0], dp[u][j - k][0] + dp[v][k][1]);

                dp[u][j][0] = max(dp[u][j][0], dp[v][j][0]);

                dp[u][j][1] = max(dp[u][j][1], dp[u][k][1] + dp[v][j-k][0]);

            }
        }
    }
}
int main() {

    while (scanf("%d%d", &n, &m) != EOF) {
        int res = 0;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
            res += val[i];
            for (int j = 0; j <= m; j++) {
                dp[i][j][1] = dp[i][j][0] = val[i];
            }
            edge[i].clear();
        }
        int a, b;
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &a, &b);
            edge[a].push_back(Node(b));
            edge[b].push_back(Node(a));
        }
        int t = n / 3 + ((n % 3) != 0 ? 1 : 0);
        if (m >= t) {
            printf("%d\n", res);
        } else {
            int p;
            for (int i = 1; i <= n; i++)
                if (edge[i].size() <= 2) {
                    p = i;
                    break;
                }
            dfs(p, 0);
            printf("%d\n", max(dp[p][m][1], dp[p][m][0]));
        }
    }
    return 0;
}
