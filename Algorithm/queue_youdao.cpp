//
// Created by BranY on 2016/8/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n, 0);
        int i ;
        for (i = 0; i < n; i++) cin >> arr[i];

        for (auto a : arr) {
            queue<int> que;
            for (i = 0; i < a; i++) que.push(i);
            i = 1;
            map<int, int> map;
            while (!que.empty()) {
                int k = que.front();
                que.pop();
                que.push(k);
                k = que.front();
                que.pop();
                map[k] = i++;
            }
            for (i = 0; i < a; i++) {
                if (i > 0) cout << " ";
                cout << map[i];
            }
            cout << endl;
        }
    }
    return 0;
}
