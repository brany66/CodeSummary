//
// Created by BranY on 2016/9/13.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
#include <vector>
#include <cmath>

using  namespace std;
int elegantPoint(int n) {
    if (n <= 0) return 0;
    int R = (int)sqrt(n);
    int l = 0, r = R, res = 0;
    while (l <= r) {
        int tmp = l*l + r*r;
        if (tmp > n){
            --r;
        } else if(tmp < n) {
            ++l;
        } else {
            res += (l == 0) ? 4 : 8;
            --r;
            ++l;
        }
    }
    return res;
}
int main() {
    int n;
    while (cin >> n) {
        cout << elegantPoint(n) << endl;
    }
    return 0;
}
