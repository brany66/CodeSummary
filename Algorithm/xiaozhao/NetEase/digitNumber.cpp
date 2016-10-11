//
// Created by BranY on 2016/9/17.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/contest/ntest2016spring1/problems

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> dict;

void init() {
    vector<int> v1 = { 0, 0, 1, 0, 0, 1, 0 };
    vector<int> v2 = { 1, 0, 1, 1, 1, 0, 1 };
    vector<int> v3 = { 1, 0, 1, 1, 0, 1, 1 };
    vector<int> v4 = { 0, 1, 1, 1, 0, 1, 0 };
    vector<int> v5 = { 1, 1, 0, 1, 0, 1, 1 };
    vector<int> v6 = { 1, 1, 0, 1, 1, 1, 1 };
    vector<int> v7 = { 1, 0, 1, 0, 0, 1, 0 };
    vector<int> v8 = { 1, 1, 1, 1, 1, 1, 1 };
    vector<int> v9 = { 1, 1, 1, 1, 0, 1, 1 };
    vector<int> v0 = { 1, 1, 1, 0, 1, 1, 1 };
    dict[0] = v0;
    dict[1] = v1;
    dict[2] = v2;
    dict[3] = v3;
    dict[4] = v4;
    dict[5] = v5;
    dict[6] = v6;
    dict[7] = v7;
    dict[8] = v8;
    dict[9] = v9;
}

void dfs(vector<vector<int>> &led, int pos, int num, int N, int &result) {
    if (pos >= led.size()) {
        if (num < N) result += 1;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        bool isOk = true;

        for (int j = 0; j < led[pos].size(); j++) {
            int ld = led[pos][j];

            if (dict[i][ld - 1] == 0) {
                isOk = false;
                break;
            }
        }

        if (isOk)
            dfs(led, pos + 1, num * 10 + i, N, result);
    }
}

int solve(vector<vector<int>> &led, int N) {
    int result = 0;
    dfs(led, 0, 0, N, result);
    return result;
}

int main() {
    init();
    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int K, N;
        cin >> K >> N;
        vector<vector<int>> led;
        cin.get();
        for (int j = 0; j < K; j++) {
            char str[100];
            cin.get(str, 100);
            vector<int> tmp;
            for (int i = 0; i < 100; i++) {
                if (str[i] == ' ') continue;
                else if (str[i] >= '0' && str[i] <= '9') tmp.push_back(str[i] - '0');
                else break;
            }
            led.push_back(tmp);
            cin.get();
        }
        cout << "result " << solve(led, N) << endl;
    }
    return 0;
}