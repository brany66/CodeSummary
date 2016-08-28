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
bool isRectangleCover(vector<vector<int>>& rectangles) {
    if (rectangles.empty() || rectangles[0].empty() || rectangles.size() == 1) return true;
    sort(rectangles.begin(), rectangles.end());

    int m = rectangles.size();
    int n = 4;
    int left = rectangles[0][0], right = rectangles[0][2];
    int down = rectangles[0][1], up = rectangles[0][3];
    int l, r;
    for (int i = 1; i < m; i++) {
        if (rectangles[i][0] > rectangles[i-1][0] && rectangles[i-1][2] != rectangles[i][0] - 1) return false;
        l = rectangles[i][2];
        r = rectangles[i][3];
    }
    return true;
}

bool insert_corner(unordered_map<int, unordered_map<int, pair<int, int>>>& corner, int x, int y, int pos) {
    pair<int, int>& p = corner[x][y];
    if (p.first & pos) return false;
    p.first |= pos;
    ++p.second;
    return true;
}
int area(const vector<int> &nums) {
    if (nums.size() != 4) return 0;
    return (nums[2] - nums[0]) * (nums[3] - nums[1]);
}
bool isRectangleCover1(const vector<vector<int>>& rectangles) {
    if (rectangles.empty() || rectangles[0].empty() || rectangles.size() == 1) return true;
    //sort(rectangles.begin(), rectangles.end());
    unordered_map<int, unordered_map<int, pair<int, int>>> corner;

    int left = INT_MAX, right = INT_MIN;
    int down = INT_MAX, up = INT_MIN;
    int m = rectangles.size();
    int totalArea = 0, sum = 0;
    sum += area(rectangles[0]);

    for (auto & rec : rectangles) {
        //if (rectangles[i][0] > rectangles[i-1][0] && rectangles[i-1][0] != rectangles[i][0] - 1) return false;
        left = min(left, rec[0]);
        down = min(down, rec[1]);
        right = max(right, rec[2]);
        up = max(up, rec[3]);
        sum += area(rec);

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
            if ((x == left || x == right) && (y == down || y == up)) {
                if ( count != 1 ) return false;
            }
            else {
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
        if (isRectangleCover1(rectangles)) {
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
