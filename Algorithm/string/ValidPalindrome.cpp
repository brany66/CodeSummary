//
// Created by BranY on 2016/8/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <algorithm>

using namespace std;
/**
 * 1. A man, a plan, a canal: Panama
 * 2. race a car
 * 3. !!!
 * 4. 0P
 * 5. a.
 * 6. Bob
 * @param s
 * @return
 */
bool isPalindrome(string s) {
    if (s.size() <= 1) return true;
    int i= 0, j = s.size() - 1;
    while (i <= j) {
        while (!isalnum(s[i]) && i < j) i++;
        while (!isalnum(s[j]) && i < j) j--;
        if (toupper(s[i]) != toupper(s[j])) return false;
        i++;
        j--;
    }
    return true;
}
int main() {
    //string s = "A man, a plan, a canal: Panama";
    //s.replace(0, 0, "[^0-9a-zA-Z]");
    //transform(s.begin(), s.end(), s.begin(), ::tolower);
    //cout << s << endl;
    string str;
    while(getline(cin, str)) {
        if (isPalindrome(str))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}
