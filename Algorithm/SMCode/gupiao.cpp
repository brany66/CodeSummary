//
// Created by BranY on 2016/9/5.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
int getValue(int n) {
    int i = 0; //多少次跌
    int j = 2; //下跌之后多少次涨，包括已经下跌的哪天
    int k = n;
    while (k > j) {
        i += 2;
        k -= j;
        ++j;
    }
    return n - i;
}

int fun(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int res = 2;
    int down = -1, up = 2;
    int k = 3;
    bool flag = false;
    while (k <= n) {
        if (flag) {
            int tmp = (n - k + 1);
            if (tmp > up) {
                k += up;
                res += up;
                up += 1;
            } else {
                res += tmp;
                break;
            }
        } else {
            if (k <= n) {
                res += down;
                k++;
            } else
                break;

        }
        flag = !flag;
    }
    return res;
}
int main() {
    int n;
    while (cin >> n) {
        cout <<getValue(n) << " *** " << fun(n) << endl;
    }
    return 0;
}
