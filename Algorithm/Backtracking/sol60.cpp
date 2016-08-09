//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//46-47
// https://leetcode.com/problems/permutation-sequence/

#include <iostream>

using namespace std;
string getPermutation(int n, int k) {
    int i, j, f=1;
    // left part of s is partially formed permutation, right part is the leftover chars.
    string s(n,'0');
    for(i = 1;i <= n;i++){
        f *= i;
        s[i-1] +=i; // make s become 1234...n
    }
    for(i = 0,k--; i < n;i++){
        f /= n-i;
        j = i + k/f; // calculate index of char to put at s[i]
        cout << "j********** " << j << " ***** " << k << "  " << f << endl;
        char c = s[j];
        // remove c by shifting to cover up (adjust the right part).
        for(; j > i; j--)
            s[j] = s[j-1];
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^ " << s << endl;
        k %= f;
        s[i] = c;
    }
    return s;
}
int main() {
    cout << getPermutation(3, 5) << endl;
    return 0;
}

