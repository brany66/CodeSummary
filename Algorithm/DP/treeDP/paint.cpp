//
// Created by BranY on 2016/10/1.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 110;
int n, m, cnt, f[maxn][maxn];
int score[maxn], pre[maxn];

struct Edge{
    int key,next;
}edge[maxn << 1];

void addEdge(int x, int y) {
    edge[cnt].key = y;
    edge[cnt].next = pre[x];
    pre[x] = cnt++;
}

void dfsDP(int cur,int p,int M) {
    if(M == 0) {
        f[cur][M] = 0;
        return;
    }
    if(f[cur][M] != -1) return;
    int num = 0,g[maxn][maxn] = {0};
    for(int i = pre[cur]; i != -1; i = edge[i].next) {
        int v = edge[i].key;
        if(v == p) continue;
        num++;
        for(int j = 0; j < M; j++)
            for(int t = 0; t <= j; t++) {
                dfsDP(v, cur, t);
                if(g[num][j] < f[v][t] + g[num-1][j-t])
                    g[num][j] = f[v][t] + g[num-1][j-t];
            }
    }
    if(f[cur][M] < g[num][M-1] + score[cur])
        f[cur][M] = g[num][M-1] + score[cur];
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        for(int i = 1; i <= n; i++)
            scanf("%d",&score[i]);

        memset(f, -1, sizeof(f));
        memset(pre, -1, sizeof(pre));
        cnt = 0;

        for(int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d",&a,&b);
            addEdge(a, b);
            addEdge(b, a);
        }
        dfsDP(1, 0, m);
        printf("%d\n", f[1][m]);
    }
    return 0;
}
