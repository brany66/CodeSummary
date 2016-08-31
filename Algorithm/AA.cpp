//
// Created by BranY on 2016/8/31.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

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
int main() {
    D d;
    d.i = 1;
    d.j = 2;
    d.k = 3;
    d.sum = d.i + d.j + d.k;
    cout << d.sum << endl;
    return 0;
}
