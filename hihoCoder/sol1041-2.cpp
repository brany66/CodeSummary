//
// Created by wuyan on 2016/7/17.
// Contact mail wyang@smail.nju.edu.cn
//
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAX_N = 101;
vector<int> graAdj[MAX_N];//邻接表
int go[MAX_N];
int graMat[MAX_N][MAX_N];//矩阵

bitset<MAX_N> hasChild[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; i++)
    {
        graAdj[i].clear();
        hasChild[i].reset();
    }
    memset(graMat, 0, sizeof(graMat));
}

void getChild(int u = 1, int par = -1)
{
    hasChild[u][u] = 1;	//自己是自己的孩子？把自己也并进孩子集合中。
    for (int i = 0; i < (int)graAdj[u].size(); i++)
    {
        int v = graAdj[u][i];
        if (v == par) continue;//防止回路，不回走父亲节点
        getChild(v, u);
        hasChild[u] |= hasChild[v];//巧妙利用bitset加速判断一个节点有多少孩子
    }
}

//利用全局变量graMat和graAdj
bool eliminateAll(int go[], int &id, int m, int u = 1, int par = -1)
{
    if (id < m && go[id] == u) id++;
    if (id == m) return true;

    while (id < m)//关键点，可以循环查找子节点
    {
        int nexta = go[id];
        int curIndex = id;
        for (int i = 0; i < (int)graAdj[u].size(); i++)
        {
            int v = graAdj[u][i];
            if (v == par) continue;//排除父节点，防止回路

            if (hasChild[v][nexta] && graMat[u][v])
            {
                graMat[u][v] = 0;//关键点：拆桥，不用重复查找路径
                if (eliminateAll(go, id, m, v, u)) return true;
            }
        }
        //关键点：防止无限循环，没有答案的时候退出
        if (id == curIndex) break;//没有找到一个对应的点a[id]，返回上一层
    }
    return false;
}

int main()
{
    int T, n, a, b, m;
    while (cin >> T) {
        while (T--)
        {
            cin >> n;
            init(n);
            for (int i = 1; i < n; i++)
            {
                cin >> a >> b;
                graAdj[a].push_back(b);
                graAdj[b].push_back(a);
                graMat[a][b] = graMat[b][a] = 1;
            }

            cin >> m;
            for (int i = 0; i < m; i++)
            {
               cin >> go[i];
            }
            getChild();
            int id = 0;
            if (eliminateAll(go, id, m)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}