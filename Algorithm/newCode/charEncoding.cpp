//
// Created by BranY on 2016/9/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int getMinEncodingLength(string &str) {
    int n = str.size();
    sort(str.begin(), str.end());
    priority_queue<int> heap;
    int cnt = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && str[j] == str[i])
            ++j;
        heap.push(i - j);
        i = j;
        ++cnt;
    }
    int res = 0;
    for (int i = 0 ; i < cnt - 1; ++i) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res -= a + b;
        heap.push(a + b);
    }
    return res;
}
int main() {
    string str;
    while (getline(cin, str)) {
       cout << getMinEncodingLength(str) << endl;
    }
    return 0;
}
