//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
//

#include <iostream>
#include <string.h>
using namespace std;
char *str1, *str2;
/**
 * 给定 2 个字符串 a, b. 编辑距离是将 a 转换为 b 的最少操作次数，操作只允许如下 3 种：
 * 1. 插入一个字符，例如：fj -> fxj
 * 2. 删除一个字符，例如：fxj -> fj
 * 3. 替换一个字符，例如：jxj -> fyj
 */

/**
 * 分治法 ： a长度是m, b长度是n
 * dp[i][j] 表示a[1]-a[i] 转化为b[1] ~ b[i]的编辑距离
 * 1. if a[i] == b[j], then dp[i][j] = dp[i-1][j-1] , 比如 fxy -> fay 的编辑距离等于 fx -> fa 的编辑距离
 * 2. if a[i] != b[j] then dp[i][j]
 *    dp[i+1][j] + 1 //(删除 a[i]),比如 fxy -> fab 的编辑距离 = fx -> fab 的编辑距离 + 1
 *    dp[i][j-1] + 1 //(插入 b[j]),比如 fxy -> fab 的编辑距离 = fxy -> fa 的编辑距离 + 1
 *    dp[i-1][j-1] + 1//(将 a[i] 替换为 b[j]), 比如 fxy -> fab 的编辑距离 = fxb -> fab 的编辑距离 + 1 = fx -> fa 的编辑距离 + 1
 *
 *<1> a[i][0] = i, b 字符串为空，表示将 a[1]-a[i] 全部删除，所以编辑距离为 i
 *<2> a[0][j] = j, a 字符串为空，表示 a 插入 b[1]-b[j]，所以编辑距离为 j
 */
int edit_distance(char *a, char *b, int i, int j) {
    if (j == 0)
        return i;
    else if (i == 0)
        return j;
    else if (a[i-1] == b[j-1]) {
        return edit_distance(a, b, i-1, j-1);
    } else {
        return min(min(edit_distance(a, b, i-1, j) + 1, edit_distance(a, b, i, j-1)+1), edit_distance(a, b, i-1, j-1)+1);
    }
}
/**
 * 计算 i = 1, j = 1 所对应的编辑距离：比较 a[i] 和 b[j] 是否相等然后根据递归规律算出这个值
 * 比如在这种情况下 a[i] = f 和 b[j] = f, 那么 d[i][j] 就等于 d[i-1][j-1] 等于 0
 * 然后计算 i = 1, j = 2 直到算出 i = 3, j = 3, 原问题的编辑距离就等于 d[3][3]
 * O(mn)
 */
int edit_distance_dp(char *a, char *b) {
    int len1 = strlen(a);
    int len2 =strlen(b);
    int dp[len1+1][len2+1];
    int i,j;
    //初始化边界条件
    for (i = 0; i <= len1; i++) dp[i][0] = i;
    for (j = 0; j <= len2; j++) dp[0][j] = j;

    for (i = 1; i <= len1; i++)
        for (j = 1; j <= len2; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);
        }
    return dp[len1][len2];
}
/**
 * Optimize Space Complexity
 */
int edit_distance_dp_spaceOpt(char *a, char *b) {
    int len1 = strlen(a);
    int len2 =strlen(b);
    int dp[len2+1];
    int i,j, old, tmp;
    for (j = 0; j <= len2; j++) dp[j] = j;

    for (i = 1; i <= len1; i++) {
        old = i - 1;
        dp[0] = i;
        for (j = 1; j <= len2; j++) {
            tmp = dp[j];
            if (a[i-1] == b[j-1])
                dp[j] = old;
            else {
                dp[j] = min(min(dp[j]+1, dp[j-1] +1), old + 1);
            }
            old = tmp;
        }
    }
    return dp[len2];
}
int main()
{
    std::string A = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string B = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
//    std::string A ="ABCBDAB";
//    std::string B = "BDCABA";
    str1 = new char[A.length() + 1];
    strcpy(str1, A.c_str());
    str2 = new char[B.length() + 1];
    strcpy(str2, B.c_str());
    //cout << edit_distance(str1, str2, strlen(str1), strlen(str2)) << endl;
    cout << edit_distance_dp(str1, str2) << endl;
    cout << edit_distance_dp_spaceOpt(str1, str2) << endl;
    return 0;
}