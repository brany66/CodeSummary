//
// Created by wuyan on 2016/7/16.
// Contact mail wyang@smail.nju.edu.cn
//
#include <iostream>
#include <limits.h>
using namespace std;
#define are(a, b, c) for (int a = b; a <=c; a++)
int ceil[105][105];
int best[105][105];

int findBest1(int n) {
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j<=i; j++)
            ceil[i][j] += max(ceil[i+1][j], ceil[i+1][j+1]);
    return ceil[1][1];
}
int findBest2(int n) {
    int ans = INT_MIN;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j<=i; j++) {
            best[i][j] = max(best[i - 1][j - 1], best[i - 1][j]) + ceil[i][j];
            if (ans < best[i][j])
                ans = best[i][j];
        }
    return ans;
}
int main()
{
    int n;
    while (cin >> n) {
        int i, j;
        for (i =1; i <= n; i++)
            for (j = 1; j <= i; j++)
                cin >> ceil[i][j];
       // cout << findBest1(n) << endl;
        cout << findBest2(n) << endl;
    }
    return 0;
}
