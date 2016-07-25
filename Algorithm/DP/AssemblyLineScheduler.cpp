//
// Created by BranY on 2016/7/22.
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// Contact at wyang@smail.nju.edu.cn
//

#include <iostream>
#include <algorithm>

using namespace std;
/**
 * Page194
 * f* = min{ f1[n] + x1, f2[n] + x2 }
 * f[1][j] = e1 + a[1][1]                                            if j == 1
 *        min{ f[1][j-1]+a[1][j] , f[2][j-1] + t[2][j-1] + a[1][j] } if j >= 2
 */
struct line {
    int e1, e2, x1, x2;
    int a1[100], a2[100], t1[100], t2[100];
};
int f1[100], f2[100], l1[100], l2[100];
int l, f;
int fastWay(line x, int len) {
    l = f = -1;
    f1[0] = x.e1 + x.a1[0];
    f2[0] = x.e2 + x.a2[0];
    for (int j = 1; j < len; j++) {
        int v1 = f1[j-1] + x.a1[j];
        int v2 = f2[j-1] + x.t2[j-1] + x.a1[j];
        if (v1 <= v2) {
            l1[j-1] = 1;
            f1[j] = v1;
        } else {
            l1[j-1] = 2;
            f1[j] = v2;
        }
        v1 = f2[j-1] + x.a2[j];
        v2 = f1[j-1] + x.t1[j-1] + x.a2[j];
        if (v1 <= v2) {
            l2[j-1] = 2;
            f2[j] = v1;
        } else {
            l2[j-1] = 1;
            f2[j] = v2;
        }
    }
    f = min(f1[len -1] + x.x1, f2[len-1] + x.x2);
    if (f == f1[len -1] + x.x1)
        l = 1;
    else l = 2;
    return f;
}
int main() {
    line x = {
            .e1 = 2, .e2 = 4, .x1 = 3, .x2 = 2,
            .a1 = {7, 9, 3, 4, 8, 4},
            .a2 = {8, 5, 6, 4, 5, 7},
            .t1 = {2, 3, 1, 3, 4},
            .t2 = {2, 1, 2, 2, 1},
    };
    int minLine = fastWay(x, 6);
    cout << "Min Line " + l  << " " << minLine << endl;
    return 0;
}
