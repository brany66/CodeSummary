//
// Created by BranY on 2016/7/22.
// Contact at wyang@smail.nju.edu.cn
//
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int XY = 0, X = 1, Y= 2;
char *str1, *str2;

int c[200][200], b[200][200];
int c1[2][200];
/**
 * Longest Common sub sequence
 * S1转变S2所需的改变最小，序列中“不必连续但保持原序列顺序”的序列。
 * S1 = ACCGGTCGAGTGCGCGGAAGCCGGCCGAA, S2 = GTCGTTCGGAATGCCGTTGCTCTGTAAA
 * S3 = GTCGTCGGAAGCCGGCCGAA
 * 令X=<x1, x2, x3, ..., xm>, Y=<y1, y2, y3, yn> 的一个LCS Z={z1,z2,...,zk}
 * if xm == yn , then zk = xm = yn, 且Zk-1 是Xm-1和Yn-1的一个LCS
 * if xm != yn , then zk != xm , 得出Z是Xm-1和Y的一个LCS
 * if xm != yn , then zk != yn , 得出Z是Xm和Yn-1的一个LCS
 *
 * 定义C[i][j]为Xi和Yj的一个LCS长度
 * c[i][j] = 0                           if i = 0 or j = 0
 *           c[i-1][j-1] + 1             if i,j > 0 && xi = yj
 *           max{c[i-1][j], c[i][j-1]}   if i, j > 0 && xi != yj
 */
string printLCS(int i, int j) {
    if (i == 0 || j == 0) return "";
    switch (b[i][j]) {
        case XY: return printLCS(i-1, j-1) + str1[i-1];
        case X: printLCS(i-1, j);
        case Y: printLCS(i, j-1);
        default: ;
    }
}
int LCS1() {
    //reset();
    int i, j;
    for (i = 0; i < strlen(str1); i++) c[i][0] = 0;
    for (j = 0; j < strlen(str2); j++) c[0][j] = 0;

    for (i = 1; i <= strlen(str1); i++) {
        for (j = 1; j <= strlen(str2); j++) {
            if (str1[i-1] == str2[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = XY;
            } else {
                if (c[i][j-1] > c[i-1][j]) {
                    c[i][j] = c[i][j-1];
                    b[i][j] = Y;
                } else {
                    c[i][j] = c[i-1][j];
                    b[i][j] = X;
                }
            }
        }
    }
    return c[strlen(str1)][strlen(str2)];
}
/**
 * 定义C[i][j]为Xi和Yj的一个LCS长度
 * c[i][j] = 0                           if i = 0 or j = 0
 *           c[i-1][j-1] + 1             if i,j > 0 && xi = yj
 *           max{c[i-1][j], c[i][j-1]}   if i, j > 0 && xi != yj
 * 只与[i-1]j-1], [i-1][j], [i][j-1]
 * int tmp1, tmp2;
 * tmp1 = c[i-1][j], 计算c[i,j-1] tmp1 = c[i-1][j-1];
 *
 */
int LCS2() {
    int i, j;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    memset(c1[0], 0, len2 * sizeof(int));
    c1[1][0] = 0;
    int tag = 1;
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                c1[tag][j] = c1[1-tag][j-1] + 1;
            }else  {
                c1[tag][j] = max(c1[1-tag][j], c1[tag][j-1]);
            }
        }
        tag = 1-tag;
    }
    return c1[1-tag][len2];
}
int main()
{
//    std::string A ="ABCBDAB";
//    std::string B = "BDCABA";
//    str1 = new char[A.length() + 1];
//    strcpy(str1, A.c_str());
//    str2 = new char[B.length() + 1];
//    strcpy(str2, B.c_str());
//    cout << str1 << " " << str2 << endl;
//    cout << "max length: " << LCS1() << ", LCS : " << printLCS(strlen(str1), strlen(str2)) << endl;

    std::string A1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string B1 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    str1 = new char[A1.length() + 1];
    strcpy(str1, A1.c_str());
    str2 = new char[B1.length() + 1];
    strcpy(str2, B1.c_str());
    cout << str1 << " " << str2 << endl;
    cout << "max length: " << LCS1()  << endl;

    cout << "max length2: " << LCS2()  << endl;
    return 0;
}

