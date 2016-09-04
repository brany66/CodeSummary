//
// Created by BranY on 2016/9/4.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[n - 1][n - 1];
    int mid = 0;
    while (l < r){
        mid = (l + r) >> 1;
        int num = 0;
        for (int i = 0; i < n; i++){
            int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            num += pos;
        }
        if (num < k){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}
int main() {
    return 0;
}
