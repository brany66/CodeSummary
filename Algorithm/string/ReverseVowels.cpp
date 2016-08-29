//
// Created by BranY on 2016/8/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;
string reverseVowels(string s) {
    auto p1 = s.begin(), p2 = s.end() - 1;
    string vowels = "aeiouAEIOU";
    while (p1 <= p2) {
        while((vowels.find(*p1) == string::npos) && (p1 < p2)) p1++;
        while((vowels.find(*p2) == string::npos) && (p1 < p2)) p2--;
        if(p1 < p2) swap(*p1, *p2);
        p1++;
        p2--;
    }
    return s;
}
int main() {
    string str;
    while (getline(cin, str)) {
        cout << reverseVowels(str) << endl;
    }
    return 0;
}
