//
// Created by BranY on 2016/8/30.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
bool canConstruct(string ransomNote, string magazine) {
    vector<int> map(26, 0);
    for (auto c : magazine) {
        int k = c - 'a';
        map[k]++;
    }
    for (auto c : ransomNote) {
        int k = c -'a';
        if (map[k] == 0) return false;
        else if (map[k] > 0) map[k]--;
    }
    return true;
}
int main() {
    string ransom, magazine;
    while (getline(cin, ransom)) {
        getline(cin, magazine);
        if (canConstruct(ransom, magazine))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
