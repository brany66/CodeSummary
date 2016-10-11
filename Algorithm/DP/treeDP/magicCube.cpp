//
// Created by BranY on 2016/10/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
int m, n, p;
const int M = 9;
const int N = 15;
int point[M][M][M];
vector<int> line[N];
int main() {
    while (scanf("%d%d%d", &m, &n, &p) != EOF) {
        memset(point, 0, sizeof(point));
        for (int x = 0; x < M; ++x) {
            for (int y = 0; y < M; y++) {
                for (int z = 0; z < M; z++) {
                    scanf("%d", &point[x][y][z]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            line[i].clear();
            int len = (int)pow(a, 3);
            int tmp;
            for (int i = 0; i < len; i++) {
                cin >> tmp;
                line[i].push_back(tmp);
            }
        }
    }
    return 0;
}
