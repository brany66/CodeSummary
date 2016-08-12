//
// Created by BranY on 2016/8/11.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
/**
 * 1. 指定n,统计[1, n]范围内1出现的次数，比如13->6, f(13)=6
 * 2. f(n)=n的最大值是多少
 */
using namespace std;
/**
 * 指定n,统计[1, n]范围内1出现的次数，比如13->6
 * 1. 若n的个位数大于1，则个位数出现1的次数=十位数上的数字加1
 * 2. 十位上出现1的个数
 * 。。。
 * f(n)=abcde
 * f(123) = 13 + 20 + 24
 */
long long  countOneNum (int n) {
    long long  iCount = 0, cin = 1, lowerNum = 0, curNum = 0, HighNum = 0;
    while (n/cin > 0) {
        lowerNum = n - (n/cin) * cin;
        curNum = (n / cin) % 10;
        HighNum = n / (cin * 10);
        switch (curNum) {
            case 0:
                iCount += HighNum * cin;
                break;
            case 1:
                iCount += HighNum * cin + lowerNum + 1;
                break;
            default:
                iCount += (HighNum + 1) * cin;
                break;
        }
        cin *= 10;
    }
    return iCount;
}
int countDigitOne(int n) {
    int res=0, a=1,b=1;
    while(n > 0) {
        res += (n + 8)/10 * a + (n %10 == 1 ? b : 0);
        b += n%10 * a;
        a *= 10;
        n /= 10;
    }
    return res;
}
int main() {
    int n;
    while (cin >> n) {
        cout << countOneNum(n) << " " << countDigitOne(n) << endl;
    }
    return 0;
}
