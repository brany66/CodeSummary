//
// Created by BranY on 2016/8/19.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
void change(vector<int> &nums, int n) {
    vector<int> ans;
    int i, j;
    for (i = n - 1, j = 2 * n - 1; i >= 0 && j >= n; --i, --j) {
        ans.push_back(nums[j]);
        ans.push_back(nums[i]);
    }
    j = 0;
    for (i = 2 * n - 1; i>= 0; --i) nums[j++] = ans[i];
}
void shuffle(vector<int> &nums, int n , int k ) {
    vector<int> ans;
    while (k--) {
        ans = nums;
        for (int i = 0; i < n; i++) {
            nums[2 * i] = ans[i];
            nums[2 * i + 1] = ans[n + i];
        }
    }
}
int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            int n, k;
            cin >> n >> k;
            vector<int> arr(2*n, 0);
            int i;
            for (i = 0;  i < 2 * n; i++) cin >> arr[i];
            //for (i = 0; i < k; i++) change(arr, n);

            for (i  = 0; i < 2 * n; i++) {
                if (i > 0) cout << " ";
                cout << arr[i];
            }
            cout << endl;
        }
    }
    return 0;
}
