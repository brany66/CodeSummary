//
// Created by BranY on 2016/9/21.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cassert>

using namespace std;
template <class T1, typename T2>
class AB {
public:
    int a;
    static int b;
    AB() {
        a = 1;
        add2();
    }
    int add1() {
        a = a + 1;
        return a;
    }
    int add2() {
        b = b+1;
        return b;
    }
};
//int AB::b = 1;
void funb(int *ip) {
    static int num = 4;
    ip = &num;
    (*ip)--;
}
int main() {
    int i = 5;
    int *ip = &i;
    funb(ip);
    cout << *ip << endl;
//    AB a1;
//    a1.add1();
//    a1.add2();
//   // assert(a1.a < AB.b);
//    cout << a1.a << " " ;
//    //<< AB.b << endl;
    return 0;
}
