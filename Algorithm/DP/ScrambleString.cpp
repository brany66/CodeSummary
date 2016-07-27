//
// Created by BranY on 2016/7/27.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
/**
 * https://leetcode.com/problems/scramble-string/
 * @return
 */
bool isScramble(string s1, string s2) {
    const int size = s1.size();
    if (s2.size() != size) return false;
    bool dp[size+1][size][size];
    fill_n(&dp[0][0][0], (size+1)*size*size, false);
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            dp[1][i][j] = (s1[i] == s2[j]);
    for (int n = 1; n <=size; n++) {
        for(i = 0; i + n <= size; i++)
            for(j = 0; j +n <= size; j++)
                for (int k = 1; k < size; k++) {
                    if ((dp[k][i][j] && dp[n-k][i+k][j+k]) ||
                            (dp[k][i][j + n - k] && dp[n-k][i+k][j])) {
                        dp[n][i][j] = true;
                        break;
                    }
                }
    }
    return dp[size][0][0];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 <<  " " << s2 << endl;
    if (isScramble(s1, s2))
        cout << "YES\n";
    else
        cout << "NO" << endl;
    return 0;
}