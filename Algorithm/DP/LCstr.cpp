//
// Created by BranY on 2016/7/22.
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// Contact at wyang@smail.nju.edu.cn
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
char *str1, *str2;

int c[200][200] ;
int c1[2][200];
/**
 * Longest Common subString
 * * c[i][j] = 0                           if i = 0 or j = 0
 *           c[i-1][j-1] + 1               if i,j > 0 && xi = yj
 *           0                             if i, j > 0 && xi != yj
 */
string LCS1() {
    //reset();
    int i, j;
    for (i = 0; i < strlen(str1); i++) {
        for (j = 0; j < strlen(str2); j++) {
            c[i][j] = 0;
        }
    }
    int maxlen = 0, maxIndex  = 0;
    for (i = 0; i < strlen(str1); i++) {
        for (j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                if (i && j)
                    c[i][j] = c[i-1][j-1] + 1;
                if (i == 0 || j == 0)
                    c[i][j] = 0;

                if (c[i][j] > maxlen) {
                    maxlen = c[i][j];
                    maxIndex = i + 1 - maxlen;
                }
            }
        }
    }
    string res = string(str1);

    return res.substr(maxIndex, maxlen);
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
//    string res = LCS1();
//    cout << "Longest Commmon SubString: " << res <<  " max length: " << res.size() << endl;

    std::string A1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string B1 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    str1 = new char[A1.length() + 1];
    strcpy(str1, A1.c_str());
    str2 = new char[B1.length() + 1];
    strcpy(str2, B1.c_str());
    cout << str1 << " " << str2 << endl;
    string res = LCS1();
    cout << "Longest Commmon SubString: " << res <<  " max length: " << res.size() << " " << c[strlen(str1)][strlen(str2)] <<endl;

    return 0;
}

