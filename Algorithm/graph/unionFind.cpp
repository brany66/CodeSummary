//
// Created by BranY on 2016/8/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://blog.csdn.net/ebowtang/article/details/41699497

#include <iostream>
#include <vector>
#include <algorithm>
/**
 * http://blog.csdn.net/dm_vincent/article/details/7655764
 * 1. 网络连接判断或者连通子图的个数
 * 如果每个pair中的两个整数分别代表一个网络节点，那么该pair就是用来表示这两个节点是需要连通的。
 * 那么为所有的pairs建立了动态连通图后，就能够尽可能少的减少布线的需要，因为已经连通的两个节点会被直接忽略掉。
 *
 * 2. 变量名等同性(类似于指针的概念)：
 * 在程序中，可以声明多个引用来指向同一对象，这个时候就可以通过为程序中声明的引用和实际对象建立动态连通图来判断哪些引用实际上是指向同一对象。
 *
 * 1. 给出两个节点，判断它们是否连通，如果连通，不需要给出具体的路径
 * 2. 给出两个节点，判断它们是否连通，如果连通，需要给出具体的路径
 */
using namespace std;

class UF {
private:
    vector<int> id;
    int count;
public :
    UF (int N) {
        count = N;
        id.resize(N);
        for (int i = 0;  i < N; i++)
            id[i] = i;
    }
    int getCount() {
        return count;
    }
    int find(int p) {
        return id[p];
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    void Union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;
        for (int i = 0; i < id.size(); i++)
            if (id[i] == pID)
                id[i] = qID;
        count--;
    }
};

class Edge {
public:
    int a, b;
    int cost;
    bool isBuild;
    bool operator < (const Edge &e)  const {
        return cost < e.cost;
    }
};
Edge edge[100];

class Quick_UF {
private:
    vector<int> id;
    int count;
public :
    Quick_UF (int N) {
        count = N;
        id.resize(N);
        for (int i = 0;  i < N; i++)
            id[i] = i;
    }
    int getCount() {
        return count;
    }
    int find(int p) {
        while (p != id[p] ) p = id[p];
        return p;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    void Union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;
        id[pID] = qID;
        --count;
    }
    int getSets(int n) {
        int count = 0;
        for (int i = 1; i <= n ; i++) {
            if (id[i] == i)
                count++;
        }
        return count;
    }

    int minCost( int m) {
        sort(edge, edge+m);
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int baseA = find(edge[i].a);
            int baseB = find(edge[i].b);
            if (baseA != baseB)  {
                id[baseA] = baseB;
                sum += edge[i].cost;
            }
        }
        return sum;
    }
};
/**
 * 假如已知有n个人和m对好友关系（存于数字r）。如果两个人是直接或间接的好友（好友的好友的好友...），
 * 则认为他们属于同一个朋友圈，请写程序求出这n个人里一共有多少个朋友圈。
 * 假如：n = 5 ， m = 3 ， r = {{1 , 2} , {2 , 3} , {4 , 5}}，表示有5个人，1和2是好友，2和3是好友，
 * 4和5是好友，则1、2、3属于一个朋友圈，4、5属于另一个朋友圈，结果为2个朋友圈。
 * @return
 */

/**
 * 题目描述：
 * 省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可
 * 现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
 * 输入：
 * 测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；
 * 随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），
 * 此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。
 * @return
 */
int main()
{
    int m, n;
    while (cin >> n, n > 0) {
        int m  = n*(n-1) / 2;
        Quick_UF set(1000);
        for (int i = 0; i < m; i++) {
            cin >> edge[i].a >> edge[i].b >> edge[i].cost >> edge[i].isBuild;
            if (edge[i].isBuild == 1)
                set.Union(edge[i].a, edge[i].b);
        }
        cout << set.minCost(m) << endl;
    }
    return 0;
}