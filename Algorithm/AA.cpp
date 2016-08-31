//
// Created by BranY on 2016/8/31.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <climits>
#include <cassert>
#include <cstring>

using namespace std;
class A {
public :
    int i;
};
class B : virtual public A {
public :
    int j;
};
class C : virtual public A {
public :
    int k;
};
class D: public B, public C {
public:
    int sum;
};
int myAtoi(string str) {
    if (str.size() == 0) return 0;
    int i = 0, res = 0;
    while (i < str.size() && str[i] == ' ') i++;

    int sign = (str[i] == '-') ? -1 : 1;
    if (str[i] == '-' || str[i] == '+') i++;
    while (i < str.size()) {
        if (!isdigit(str[i])) break;
        int digit = str[i] - '0';
        cout << digit << "----" << endl;
        if (sign == -1 && res > -((INT_MIN + digit) / 10))
            return INT_MIN;
        else if (sign == 1 && res > ((INT_MAX - digit) / 10))
            return INT_MAX;
        res = res * 10 + digit;
        i++;
    }

    return sign * res;
}
int main() {
    D d;
    d.i = 1;
    d.j = 2;
    d.k = 3;
    d.sum = d.i + d.j + d.k;
    cout << d.sum << endl;
    string str;
    while (getline(cin, str)) {
        cout << myAtoi(str) << endl;
    }
    return 0;
}
