//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//http://hihocoder.com/problemset/problem/1044
//

#include <iostream>
#include  <string.h>
using namespace std;
/**
 * 小Hi和小Ho所处的车厢可以被抽象成连成一列的N个位置，按顺序分别编号为1..N，每个位置上都有且仅有一名乘客在休息。
 * 同时每个位置上都有一些垃圾需要被清理，其中第i个位置的垃圾数量为Wi。乘务员可以选择其中一些位置进行清理，但是值得注意的是，
 * 一旦有编号连续的M个位置中有超过Q个的位置都在这一次清理中被选中的话（即这M个位置上的乘客有至少Q+1个被惊醒了），就会发生令人不愉快的口角
 * 而小Hi和小Ho的任务是，计算选择哪些位置进行清理，在不发生口角的情况下，清扫尽可能多的垃圾。
 *
 * [0, M-1]选取了位置的个数为Sum，if Sum < Q，那么我当前就有两种决策方案——选与不选，不然就就只有不选这一种方案。
 * 0：不选， 1：选取
 * 以best(i, p1, p2, p3, ... , pM-1)表示当前已经决定了编号为1..i的位置，并且第(i-j+1)个位置是否选取用pj进行记录的情况下最多可以清扫的垃圾数量！
 *
 * best(i, p1, p2, p3, ... , pM-1) + wi+1 --> best(i+1, 1, p1, p2, ..., pM-2) sum(p[1,M-1]) < Q
 * best(i, p1, p2, p3, ... , pM-1) --> best(i+1, 0, p1, p2, p3, ... , pM-2)
 * s为二进制串
 * best(i, s) +wi+1 --> best(i+1, s/2 + 2^(M-2)) s的二进制数位和 < Q
 * best(i, s) -> best(i+1, s/2)
 *
 * 5 2 1
 * 36 9 80 69 85
 */
int N, M , Q;
int w[1002], dp[1002][1 << 10], ok[1 << 10];

void init() {
    memset(ok, 0, sizeof(ok));
    int val, cnt;
    for (int i = 0; i < (1 << M); i++) {
        val = i;
        cnt = 0;
        while (val > 0) {
            cnt += val & 1;
            val >>= 1;
        }
        ok[i] = (cnt <= Q);
    }
}
void solve() {
    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < (1 << M); j++) {
            if (dp[i-1][j] != -1) {
                int s0 = ((j << 1) & ((1 << M) - 1));
                int s1 = ((j << 1) | 1) & ((1 << M) -1);
                cout << "i " << i << " j " << j << " s0 " << s0 << " s1 " << s1 << endl;
                dp[i][s0] = max(dp[i][s0], dp[i - 1][j]);
                if (ok[s1]) {
                    dp[i][s1] = max(dp[i][s1], dp[i - 1][j] + w[i]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << M); i++) ans = max(ans, dp[N][i]);
    cout << ans << endl;
}
int main()
{
    while (cin >> N >> M >> Q) {
        init();
        for(int i = 1; i <= N; i++) cin >> w[i];
        for (int i = 0; i < (1 << M); i++) {
            cout << ok[i] << " ";
        }
        cout << endl;
        solve();
    }
    return 0;
}