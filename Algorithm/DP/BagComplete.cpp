//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
// http://hihocoder.com/problemset/problem/1043

#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
int N, M;
int need[502], value[502];
int dp[502][100002];
int dp1[100005];

void bag_dp_1() {
    int i, j, k;
    for (i = 1; i <= N; i++)
        for (j = 0; j <= M; j++) {
            if (j < need[i])
                dp[i][j] = dp[i-1][j];
            int best = INT_MIN;
            for (k = 0; k <= j/need[i]; k++) {
                int tmp = max (dp[i][j], dp[i-1][j - need[i] * k] + value[i] * k);
                if (best < tmp)
                    best = tmp;
            }
            dp[i][j] = best;
        }
}
/**
 * dp(i, x)表示已经决定了前i件物品是否选取，当前已经选取的物品的所需奖券数总和不超过x时，能够获取的最高的喜好值的和
 *
 * dp[i][j] = max{ (dp[i-1][j - need[i] * k]) + value[i] * k }         k ->[0, x/need[i]]
 * dp[i][x-need[i]] = max {(dp[i-1][j - need[i] * k]) + value[i] * k } k ->[1, x/need[i]]
 *
 * dp[i][j] = max{dp[i][j-need[i]] + value[i], dp[i-1][j]}
 * dp[i][j]表示前i件物品选多少件，不超过j,能获得的最高喜好值
 */
void bag_dp_2() {
    int i, j;
    for (j = 0; j <= M; ++j) dp[0][j] = 0;
    for (i = 0; i <= N; ++i) dp[i][0] = 0;

    for (i = 1; i <= N; i++) {
        for (j = 0; j <= M; j++) {
            if (j >= need[i])
                dp[i][j] = max(dp[i-1][j], dp[i][j - need[i]] + value[i]);
            else
                dp[i][j] =dp[i-1][j];
        }
    }
}
/**
 * 1 : 不要， 2：要一个 3：要多个
 * dp(i, x)表示已经决定了前i件物品是否选取，当前已经选取的物品的所需奖券数总和不超过x时，能够获取的最高的喜好值的和
 * dp[i][j] = max{ (dp[i-1][j - need[i] * k]) + value[i] * k } k ->[0, x/need[i]]
 * dp[i][x-need[i]] = max {(dp[i-1][j - need[i] * k]) + value[i] * k } k ->[1, x/need[i]]
 *
 * dp[i][j] = max{dp[i][j-need[i]] + value[i], dp[i-1][j]}
 * dp[i][j]表示前i件物品选多少件，不超过j,能获得的最高喜好值
 * dp[i][j] = 0                                                     if i =0 or j = 0
 *            dp[i-1][j]                                             if j < need[i]
 *            max{dp[i-1][j], dp[i][j-need[i]] + value[i] }          if i > 0 && j >= need[i]
 * optimize
 * i ->[1, N] j -> [need[i], M]
 * dp1[j] = max (dp1[j], dp1[j - need[i]] + value)
 */
void bag_dp_3() {
    memset(dp1, 0, sizeof(dp1));
    for (int i = 1; i <= N; i++)
        for (int j = need[i]; j < M; j++)
            dp1[j] = max(dp1[j], dp1[j - need[i]] + value[i]);
}
int main() {
    while (cin >> N >> M) {
        int i, j;
        for (i = 1; i <= N; i++)
            cin >> need[i] >> value[i];
        bag_dp_2();
        cout << dp[N][M] << endl;
        bag_dp_3();
        cout << dp1[M - 1] << endl;
    }
    return 0;
}


/**
5 1000
144 990
487 436
210 673
567 58
1056 897
 */