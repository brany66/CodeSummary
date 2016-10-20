//
// Created by BranY on 2016/9/11.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> getGray(int n) {
    // write code here
    vector<string> res;
    if (n == 1) {
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    vector<string> tmp = getGray(n - 1);
    for (int i = 0; i < tmp.size(); i++)
        res.push_back("0" + tmp[i]);
    for (int i = tmp.size() - 1; i >= 0; --i) {
        res.push_back("1" + tmp[i]);
    }
    return res;
}
void help(string &str) {
    if (str.size() <= 1) return;
    int end = str.size();
    for (int i  = 0; i < end; i++) {
        if (isupper(str[i])) {
            int j = i;
            while (j < str.size() - 1) {
                swap(str[j], str[j+1]);
                ++j;
            }
            --end;
            //--i;
        }
    }
}
string num2binary(int bit, int n) {
    string ret = "";
    for(int i = n-1; i >= 0; i--){
        ret += (bit >> i) & 1;
    }
    return ret;
}
void getGrayCode(int n) {
    int len = (int)pow(2, n);
    for (int i = 0 ; i < len; i++) {
        int bit = ( i >> 1) ^ i;
        cout << num2binary(bit, n) << endl;
    }

}

int main() {
//    string str;
//    while (getline(cin, str)) {
//        help(str);
//        cout << str << endl;
//    }
    int n;
    while (cin >> n) {
        getGrayCode(n);
    }
    return 0;
}
