//
// Created by BranY on 2016/10/12.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int add, carry;
    do {
        add = a ^ b;
        carry = (a & b) >> 1;
        a = add;
        b = carry;
    }while (carry != 0);
    cout << add << endl;
    return 0;
}
