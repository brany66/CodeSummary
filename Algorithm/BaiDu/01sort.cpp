//
// Created by BranY on 2016/9/13.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
int sortRes(string &str) {
    if (str.size() <= 1) return 0;
    int l = 0, r = str.size() - 1;
    int res = 0;
    while (l < r) {
        while (l < r && str[l] == '0') ++l;
        while (l < r && str[r] == '1') --r;
        if (l < r) {
            swap(str[l], str[r]);
            ++res;
            ++l;
            --r;
        }
    }
    return res;
}
int main() {
    int t;
    while(cin >> t) {
        while (t--) {
            string str;
           // getline(cin, str);
            cin >> str;
            cout << sortRes(str) << endl;
        }
    }
    return 0;
}
