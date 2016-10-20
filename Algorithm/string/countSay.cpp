//
// Created by BranY on 2016.10.19.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;
void countSay(int n) {
    if (0 == n) cout << "" << endl;
    if (1 == n) cout << "1" << endl;
    string res = "1";
    string s;
    for (int i = 1; i < n; ++i) {
        int len = res.size();
        for (int j = 0; j < len; j++){

            int count = 1;
            while ((j + 1 < len) && (res[j] == res[j + 1])){
                count++;
                j++;
            }
            stringstream in;
            in << count;
            s += in.str() + res[j];
            //s += res[j];
            in.clear();
            //s += std::to_string(count) + res[j];
        }
        res = s;
        s.clear();
    }
    cout << res << endl;
}
int main() {
    int n;
    while (cin >> n) {
        countSay(n) ;
    }
    return 0;
}
