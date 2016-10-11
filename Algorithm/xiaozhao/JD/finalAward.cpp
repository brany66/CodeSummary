//
// Created by BranY on 2016/9/5.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int getMost(vector<vector<int> > board) {
    // write code here
    if (board.empty() || board[0].empty()) return -1;
    int res = 0;
    int m = board.size();
    int n = board[0].size();
    vector<vector<int> > dp(m, vector<int>(n, 0));
    int i, j;
    for (i = 1; i < m; i++)
        board[i][0] += board[i-1][0];
    for (j = 1; j < n; j++)
        board[0][j] += board[0][j-1];
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            board[i][j] += max(board[i-1][j], board[i][j-1]);
        }
    }
    return board[m-1][n-1];
}
/**
 * 一共n头(n大于1小于9)熊来分
 *
 * 第一头为小东，它把苹果均分n份后，多出了一个，它扔掉了这一个，拿走了自己的一份苹果，
 * 接着第二头熊重复这一过程，即先均分n份，扔掉一个然后拿走一份，
 * 以此类推直到最后一头熊都是这样(最后一头熊扔掉后可以拿走0个，也算是n份均分)。
 * 问最初这堆苹果最少有多少个。
 * n ^ 2 + 1 - n
 */

int getInitial(int n) {
    // write code here
    if (n < 1 || n > 9) return 0;
    int i= 0, res;
    while (1) {
        res = i * n + 1;
        int t = res;
        bool flag = true;
        for (int j = n; j > 0; --j) {
            if (t % n == 1)
                t = t/n * (n - 1);
            else {
                flag = false;
                break;
            }
        }
        if (flag) return res;
        i++;
    }
    return res;
}
void clearSpace(string &str) {
    int i= 0, j = 0;
    while (str[i] == ' ') i++;
    while (i < str.size()) {
        if (str[i] == ' ' && ( i == str.size() - 1 || str[i+1] == ' ')) {
            i++;
            continue;
        }
        str[j++] = str[i++];
    }
    str = str.substr(0, 18);
    //auto pos = str.find_last_of(" ");
    //str = str.substr(0, str.size() - pos);
    //return ;
}
void FormatString(char str[], int len){
    int i = 0, j= 0;
    while(str[i] == '-') i++;

    while (i < len) {
        if ((str[i] == '-') &&(i == len - 1 || str[i+1] == '-')) {
            i++;
            continue;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';
    //char *tmp = str;
    //strncpy(str, tmp, j);
    //cout << i << " " << j << endl;
}
/**
 * 有n枚硬币按照0到n-1对它们进行编号，其中编号为i的硬币面额为vi，两个人轮流从剩下硬币中取出一枚硬币归自己所有，
 * 但每次取硬币的时候只能取剩下的硬币中编号最小的硬币或者编号最大的硬币，在两个都采用最优策略的情况下，
 * 作为先取硬币的你请编写程序计算出你能获得硬币总面额的最大值？（请简述算法原理，时间复杂度并实现具体的程序），语言不限。
 *
 *
 * 当只剩1个硬币的时候： dp[i][i] = v[i]    //只能拿这个，无悬念
 * 当只剩2个硬币的时候： dp[i][i + 1] = max(v[i], v[i + 1])    //一定选最大的
 * 当剩余硬币>=3个时，需要知道第二个人的策略：
 *
 * dp[i][j] = max(拿第一个 + 第二个人选择后剩下的能够拿到的最大值，  拿最后一个 + 第二个人选择后剩下的能够拿到的最大值）
 */
int MaxValue(vector<int> v, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> prev(n, vector<int>(n, 0));
    int i;
    for (i = 0; i < n; i++) {
        dp[i][i] = v[i];
        prev[i][i] = i;
    }
    for (i = 2; i <= n; i++) {
        for (int j = 0; j + i <= n; j++) {
            int e = i + j - 1;
            int a = v[j], b = v[e];
            if (i >= 3) {
                if (prev[j + 1][e] == j + 1)
                    a += dp[j+2][e];
                else
                    a += dp[j+1][e-1];
                if (prev[j][e-1] == j) {
                    b += dp[j+1][e-1];
                } else {
                    b += dp[j][e-2];
                }
            }
            prev[j][e] = (a > b) ? j : e;
            dp[j][e] = (a > b) ? a : b;
        }
    }
    return dp[0][n-1];
}
int main() {
    int n;
    string str = "   i   am a      little boy.    ";
    clearSpace(str);
    cout << "Use String : " << str << endl;
    char s[] = "---i---am-a-----little boy.------";
   // cout << str << endl;
    FormatString(s, strlen(s));
    cout << s << endl;
    while (cin >> n) {
        cout << getInitial(n) << endl;
    }
    return 0;
}
