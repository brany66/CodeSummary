//
// Created by wuyan on 2016/7/17.
// Contact mail wyang@smail.nju.edu.cn
//
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;
const int MAX = 105;
int head[MAX], tol;
struct Edge {
    int v, next;
}e[MAX * 2];
int n, m;
bitset<MAX> bt[MAX];
int go[MAX];
int current;
bool visit[MAX];
void addEdge(int u, int v) {
    e[tol].v = v; e[tol].next = head[u]; head[u] = tol++;
    e[tol].v = u; e[tol].next = head[v]; head[v] = tol++;
}
void prop(int u, int p) {
    //dfs1
    bt[u].set(u);
    int v;
    for (int k = head[u]; k != -1; k = e[k].next) {
        v = e[k].v;
        if (v != p) {
            prop(v, u);
            bt[u] |= bt[v];
        }
    }
}
bool dfs(int u) {
    if (go[current] == u) current++;
    if (current == m) return true;
    visit[u] = true;
    while (current < m ) {
        int tmp = current;
        for (int k = head[u]; k != -1; k = e[k].next) {
            int v = e[k].v;
            if (bt[v].test(go[current]) && !visit[v]) {
                visit[v] = true;
                if(dfs(v)) return true;
            }
        }
        if (current == tmp) return false;
    }
    return false;
}
int main()
{
    int t, n, m;
    while (cin >> t) {
        while (t--) {
            tol = 0;
            memset(head, -1, sizeof(head));
            int u, v , i;
            cin >> n;
            for (i = 1; i < n; i++) {
                cin >> u >> v;
                addEdge(u, v);
            }
            cin >> m;
            for (i = 0; i< m; i++) cin >> go[i];
            for (i = 1; i <= n; i++) bt[i].reset();
            prop(1, -1);
            current = 0;
            memset(visit, false, sizeof(visit));
            if (dfs(1)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

    }
    return 0;
}
