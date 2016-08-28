//
// Created by BranY on 2016/8/28.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isRectangleCover(vector<vector<int>>& rectangles) {
    if (rectangles.empty() || rectangles[0].empty() || rectangles.size() == 1) return true;
    sort(rectangles.begin(), rectangles.end());

    int m = rectangles.size();
    int n = 4;
    int left = rectangles[0][0], right = rectangles[0][2];
    int down = rectangles[0][1], up = rectangles[0][3];
    int l, r;
    for (int i = 1; i < m; i++) {
        if (rectangles[i-1][0] != rectangles[i][0] - 1) return false;
    }
    return true;
}
int main() {
    int T;
    while (cin >> T) {
        vector<vector<int>> rectangles(T, vector<int>(4, 0));
        for (int i = 0; i < T; ++i) {
            cin >> rectangles[i][0] >> rectangles[i][1] >> rectangles[i][2] >> rectangles[i][3];
        }
        bool flag = isRectangleCover(rectangles);
        if (isRectangleCover(rectangles)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        //sort(rectangles.begin(), rectangles.end());
//        cout << "[" << endl;
//        for (auto a : rectangles) {
//            cout << "  [";
//            for (auto c : a) {
//                cout << c << " ";
//            }
//            cout << "]\n";
//        }
//        cout << "]" << endl;
    }
    return 0;
}
