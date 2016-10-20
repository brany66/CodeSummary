//
// Created by BranY on 2016/8/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;
ll dfs (ll h, ll i, ll j) {
    ll a = i, b = j;
    ll preA = 0, preB = 0;
    while (a < b) {
        ll m = a + (b-a)/2;
        ll A = m*(m+1);
        if ((A-h) < 0)
            a = m;
        else if((A-h) > 0)
            b = m;
        if (preA == a && preB == b) {
            return min(a, b);
        }
        preA = a;
        preB = b;
    }
    return a;
}
int main()
{
    ll h;
    while(cin >> h) {
        cout << dfs(h, 1, h) << endl;
    }
    vector<int> xx;
    list<char> ll;
    return 0;
}