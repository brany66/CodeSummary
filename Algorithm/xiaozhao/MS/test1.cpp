//
// Created by BranY on 2016/10/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
const int N = 1000005;
bool check(int a, int b) {
    if (((a & 1)&& !(b & 1) )|| (!(a & 1)&& (b & 1))) return true;
    else return false;
}
int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n, 0);
        vector<bool> map(n, true);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int l = 0, r = 1;
        while (r < n && !check(arr[r], arr[l])) r++;
        int ans = n;
        while (l < n) {
            while (l < n && !map[l]) l++;
            while (r < n){
                if (check(arr[l], arr[r]))
                    break;
                else
                    r++;

            };
            if (l == r || r >= n || l >= n) break;
            ans -= 2;
            map[l] = map[r] = false;
            ++l;
            ++r;
        }
        cout << ans << endl;
    }

    return 0;
}
