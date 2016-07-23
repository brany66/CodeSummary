//
// Created by wuyan on 2016/7/17.
// Contact mail wyang@smail.nju.edu.cn
//
#include <iostream>
#include <cstring>
using namespace std;
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
                //cout << "i " << i << " j " << j << " s0 " << s0 << " s1 " << s1 << endl;
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
int main() {
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
