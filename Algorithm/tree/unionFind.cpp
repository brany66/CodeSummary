//
// Created by BranY on 2016/8/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
/**
 * http://blog.csdn.net/dm_vincent/article/details/7655764
 * 1. 网络连接判断
 * 如果每个pair中的两个整数分别代表一个网络节点，那么该pair就是用来表示这两个节点是需要连通的。
 * 那么为所有的pairs建立了动态连通图后，就能够尽可能少的减少布线的需要，因为已经连通的两个节点会被直接忽略掉。
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
        count--;
    }
};
int main()
{
    return 0;
}