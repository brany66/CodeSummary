//
// Created by BranY on 2016/9/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
using namespace std;
int t, n, r, finalCnt;
bool is2;
void dfs(int x, int m) {
    if(x <= 3) {
        finalCnt = x;
        is2 = (m == 3);
        return ;
    }
    ++r;
    return dfs(x - x/m, m == 2 ? 3 : 2);
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        r = 0;
        dfs(n, 2);
        cout << "1";
        for(int i = 2; i <= finalCnt; ++i) {
            int tmp = i;
            bool is = is2;
            for(int j = 0;j < r; ++j) {
                if(is) {
                    tmp = tmp * 2-1;
                } else {
                    tmp = (tmp * 3 - 1) / 2;
                }
                is = !is;
            }
            cout << " " << tmp;
        }
        cout << endl;
    }
    return 0;
}