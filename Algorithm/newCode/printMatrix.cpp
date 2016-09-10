//
// Created by BranY on 2016/9/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
void printMatrix(const vector<vector<int>> &arr) {
    int n = arr.size();
    vector<int> res(n*n , 0);
    if (arr.empty() || arr[0].empty()) return;
    // left corner
    int p = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j) {
            res[p] = arr[j][i+j];
            res[n*n - p - 1] = arr[n-1-j][n-1-i-j];
            p++;
        }
    }
    cout << res[0];
    for (int i = 1; i < res.size(); i++)
        cout << "," << res[i];
    cout << endl;
}
int get(int n) {
    int b = 1;
    while(b < n) {
        b <<= 1;
    }
    return (b >> 1) - 1;
}
int main() {
    int n;
    while (cin >> n) {
        cout << get(n) << endl;
        int k = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = k++;
            }
        }
        //printMatrix(res);
    }
    return 0;
}
