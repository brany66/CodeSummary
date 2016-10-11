//
// Created by BranY on 2016/10/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;
const int M = 105;

struct Node {
    int S;
    int arrive;
    int n;
    map<int, int> index;
    Node(int a, int b, int c, map<int, int> &d) : S(a), arrive(b), n(c), index(d) {}
};
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        if (a.arrive > b.arrive) return true;
        else
            return false;
    }
};
int n, m, k;
int main() {
    while (cin >> n >> m >> k) {
        priority_queue<Node, vector<Node>, cmp> index;

        for (int i = 0; i < n; i++) {
            int s, arrT, p;
            map<int, int> tmp;
            cin >> s >> arrT >> p;
            for (int j = 0; j < p; j ++) {
                int a, b;
                cin >> a >> b;
                tmp[a] = b;
            }
            index.push(Node(s, arrT, p, tmp));
        }
        while (index.size() > 0) {
            auto c = index.top();
            c.arrive += 100;

        }
    }
    return 0;
}
