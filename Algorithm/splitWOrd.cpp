//
// Created by BranY on 2016/8/13.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://www.nowcoder.com/practice/d9162298cb5a437aad722fccccaae8a7?tpId=37&tqId=21227&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking


#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <map>


using namespace std;
void process(vector<string> &res, string str) {
    int pos = 0;
    while (pos < str.size()) {
        if (pos + 7 < str.size()) {
            res.push_back(str.substr(pos, 8));
            pos += 8;
        } else {
            string tmp = str.substr(pos);
            int len = 8 - tmp.size();
            for (int i = 0; i < len; i++) tmp.push_back('0');
            res.push_back(tmp);
            break;
        }
    }
}

int getValue(int n) {
    if (n == 1) return 1;
    bool up = true;
    int upVal = 0, sum = 1;
    int pos = 2;
    while (pos <= n) {
        ++upVal;
        if (pos + upVal > n) {
            sum += n - pos + 1;
            break;
        }
        pos += upVal;
        sum += upVal;

        if (pos > n) break;
        pos += 1;
        sum -= 1;
    }
    return sum;
}
int main() {
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    vector<string> res;
    process(res, str1);
    process(res, str2);

    for (auto c : res)
        cout << c << endl;

    int n;
    while (cin >> n) {
        cout << getValue(n) << endl;
    }
    map<string, int> map;
    pair<string, int> p("HW", 1);
    
    return 0;
}
