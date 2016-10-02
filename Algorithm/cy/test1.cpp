//
// Created by BranY on 2016/9/24.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <regex>

using namespace std;
struct Test1 {
    Test1() {
        cout << "Constructor Test1" << endl;
    }
    Test1(const Test1 &t1) {
        cout << "Copy Constructor for Test1" << endl;
        this->a = t1.a;
    }
    Test1&operator=(const Test1 &t1) {
        cout << "assignment for Test1" << endl;
        this->a = t1.a;
        return *this;
    }
    int a;
};
struct Test2{
    Test1 t1;
    Test2(Test1 &t) {
        t1 = t;
    }
};
int main() {
//    Test1 t1;
//    Test2 t2(t1);
    int x = 65530;
    int res  = 0;
    while (x) {
        res++;
        x &= (x-1);
    }
    cout << res << endl;
    return 0;
}
