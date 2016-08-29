//
// Created by BranY on 2016/8/28.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;
int area(const vector<int> &nums) {
    if (nums.size() != 4) return 0;
    return (nums[2] - nums[0]) * (nums[3] - nums[1]);
}
bool insert_corner(unordered_map<int, unordered_map<int, pair<int, int>>>& corner, int x, int y, int pos) {

    pair<int, int>& p = corner[x][y];
    //cout << p.first << " " << p.second << endl;
    if (p.first & pos) return false;
    p.first |= pos;
    ++p.second;
    return true;
}
bool isRectangleCover(const vector<vector<int>>& rectangles) {
    if (rectangles.empty() || rectangles[0].empty() || rectangles.size() == 1) return true;
    //sort(rectangles.begin(), rectangles.end());
    unordered_map<int, unordered_map<int, pair<int, int>>> corner;

    int left = INT_MAX, right = INT_MIN;
    int down = INT_MAX, up = INT_MIN;
    int totalArea = 0, sum = 0;
    sum += area(rectangles[0]);

    for (auto & rec : rectangles) {
        //if (rectangles[i][0] > rectangles[i-1][0] && rectangles[i-1][0] != rectangles[i][0] - 1) return false;
        left = min(left, rec[0]);
        down = min(down, rec[1]);
        right = max(right, rec[2]);
        up = max(up, rec[3]);
        //sum += area(rec);

        if (!insert_corner(corner, rec[0], rec[1], 1)) return false;
        if (!insert_corner(corner, rec[2], rec[1], 2)) return false;
        if (!insert_corner(corner, rec[0], rec[3], 4)) return false;
        if (!insert_corner(corner, rec[2], rec[3], 8)) return false;
    }
    vector<int> tmp = {left, down, right, up};
    totalArea = area(tmp);
    if (totalArea != sum) return false;

    for (auto itx = corner.begin(); itx != corner.end(); ++itx) {
        int x = itx->first;
        for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
            int y = ity->first;
            int count = ity->second.second;
            //在外层边上的交点
            if ((x == left || x == right) && (y == down || y == up)) {
                if (count != 1) return false;
            }
            else { //内边上的交点
                if (count !=2 && count !=4) return false;
            }
        }
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
