//
// Created by BranY on 2016/8/12.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
typedef long long ll;
int gcd_1(int x, int y) {
    return (y == 0) ? x : gcd_1(y, x % y);
}
ll gcd(ll x, ll y) {
    if (x < y)
        return gcd(y, x);
    if (y == 0)
        return x;
    else {
        if (x & 1 == 0) {
            if (y & 1 == 0)
                return gcd(x >> 1, y >> 1) << 1;
            else
                return gcd(x >> 1, y);
        } else {
            if (y & 1 == 0)
                return gcd(x, y >> 1);
            else
                return gcd(y, x - y);
        }
    }
}
int main() {
    return 0;
}
