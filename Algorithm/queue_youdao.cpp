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
        int i;
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (auto a: arr) {
            queue<int> que;
            map<int, int> map;
            for (i = 0; i < a; i++) que.push(i);

            i =  1;
            while (!que.empty()) {
                int x = que.front();
                que.pop();
                que.push(x);
                x = que.front();
                que.pop();
                map[x] = i++;
            }

            for (i = 0;  i < a; i++) {
                if (i > 0) cout << " ";
                cout << map[i];
            }
            cout << endl;
        }
    }
    return 0;
}
