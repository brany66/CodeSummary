//
// Created by BranY on 2016/8/22.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int firstUniqChar(string s) {
    vector<int> res(26, 0);
    if (s.size() == 0) return -1;
    int i;
    for (i = 0; i < s.size(); i++) {
        int k = s[i] - 'a';
        ++res[k];
    }
    int index = -1;
    for (i = 0; i < s.size(); i++) {
        int k = s[i] -'a';
        if(res[k] == 1) {
            index = i;
            break;
        }
    }
    return index;
}
int main() {
    string str;
    while (getline(cin, str)) {
        cout << firstUniqChar(str) << endl;
    }
    return 0;
}
