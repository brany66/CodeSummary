//
// Created by BranY on 2016/9/5.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
void snake(vector<vector<int>> &mat, int n) {
    if (mat.empty() || mat[0].empty() || n == 1) return;
    int layer = (n+1)/2;
    int k = 1;
    for (int i = 0; i < layer; i++) {
        //right
        for (int right = layer; right < n - layer - 1; right++)
            mat[right][n - layer - 1] = k++;
        //down
        for (int down = n - layer - 1; down > 0; --down)
            mat[n - layer - 1][down] = k++;
        //left
        for (int left = n - layer - 1; left > 0; --left)
            mat[left][layer] = k++;
        //up
        for (int up = layer; up < n - layer - 1; up++)
            mat[layer][up] = k++;
    }
}
int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> mat(n, vector<int>(n, 1));
        snake(mat, n);
        for (int i = 0; i < n; i++) {
            cout << mat[i][0];
            for (int j = 1; j < n; j++) {
                cout <<  " " << mat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
