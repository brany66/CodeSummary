//
// Created by BranY on 2016/9/6.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
/**
 * 计算字符串的相似度
 * 可以修改，增加，和删除
 * String A, String B
 * lenA, lenB
 * 一步操作之后：
 * 1. 计算A[1,...lenA-1]与B[0,..,lenB-1]
 * 2. 计算A[0,...lenA-1]与B[1,...,lenB-1]
 * 3. 计算A[1,..,lenA-1]与B[1,...,lenB-1]
 */
using namespace std;
int calculateStrDistance(string &str1, int pABegin, int pAEnd,  string &str2, int pBBegin, int pBEnd) {
    if (pABegin > pAEnd) {
        if (pBBegin > pBEnd) return 0;
        else
            return pBEnd - pBBegin + 1;
    }
    if (pBBegin > pBEnd) {
        if (pABegin > pAEnd) return 0;
        else return pAEnd - pABegin + 1;
    }
    if (str1[pABegin] == str2[pBBegin]) {
        return calculateStrDistance(str1, pABegin + 1, pAEnd, str2, pBBegin + 1, pBEnd);
    } else {
        int t1 = calculateStrDistance(str1, pABegin, pAEnd, str2, pBBegin + 1, pBEnd);
        int t2 = calculateStrDistance(str1, pABegin + 1, pAEnd, str2, pBBegin, pBEnd);
        int t3 = calculateStrDistance(str1, pABegin + 1, pAEnd, str2, pBBegin + 1, pBEnd);

        return min(t1, min(t2, t3)) + 1;
    }
}

int calculateStrDistance_2(string &str1, int pABegin, int pAEnd,  string &str2, int pBBegin, int pBEnd) {
    vector<vector<int>> dp(100, vector<int>(100, 0));
    if (pABegin > pAEnd) {
        if (pBBegin > pBEnd) return 0;
        else
            return pBEnd - pBBegin + 1;
    }
    if (pBBegin > pBEnd) {
        if (pABegin > pAEnd) return 0;
        else return pAEnd - pABegin + 1;
    }
    if (str1[pABegin] == str2[pBBegin]) {
        if (dp[pABegin + 1][pBBegin+1] != 0)
            return dp[pABegin+1][pBBegin+1];
        else {
            dp[pABegin + 1][pBBegin + 1] =
                    calculateStrDistance_2(str1, pABegin + 1, pAEnd, str2, pBBegin + 1, pBEnd);
            return dp[pABegin+1][pBBegin + 1];
        }
    } else {
        int t1, t2, t3;
        if (dp[pABegin+1][pBBegin+1] != 0)
            t1 = dp[pABegin+1][pBBegin+1];
        else {
            t1 = calculateStrDistance_2(str1, pABegin + 1, pAEnd, str2, pBBegin+1, pBEnd);
            dp[pABegin+1][pBBegin+1] = t1;
        }

        if(dp[pABegin+1][pBBegin] != 0)
            t2 = dp[pABegin+1][pBBegin];
        else {
            t2 = calculateStrDistance_2(str1,pABegin+1,pAEnd,str2,pBBegin,pBEnd);
            dp[pABegin + 1][pBBegin] = t2;
        }

        if(dp[pABegin][pBBegin+1] != 0)
            t3 = dp[pABegin][pBBegin+1];
        else {
            t3 = calculateStrDistance_2(str1,pABegin,pAEnd,str2,pBBegin+1,pBEnd);
            dp[pABegin][pBBegin+1] = t3;
        }
        return min(t1, min(t2, t3)) + 1;
    }
}
int main() {
    string str1, str2;
    while (true) {
        getline(cin, str1);
        getline(cin, str2);

        int cal = calculateStrDistance(str1, 0, str1.size(), str2, 0, str2.size());
        cout << calculateStrDistance(str1, 0, str1.size(), str2, 0, str2.size()) <<  "    "
         << calculateStrDistance_2(str1, 0, str1.size(), str2, 0, str2.size())  << endl;
    }
    return 0;
}
