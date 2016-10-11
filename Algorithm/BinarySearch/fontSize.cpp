//
// Created by BranY on 2016/10/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://hihocoder.com/problemset/problem/1288

#include <iostream>
using namespace std;
int n, p, w, h, ans;
int a[2000];

int check(int x) {
    int num = w / x, line = p * (h / x);
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += (long long) a[i] / num;
        if(a[i] % num)
            sum++;
    }
    if (sum > line) return 0;
    return 1;
}
int bs() {
    int l = 1, r = min(w, h), mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (!check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    return r;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p >> w >> h;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << bs() << endl;
    }
    return 0;
}
