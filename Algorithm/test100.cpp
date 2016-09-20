//
// Created by BranY on 2016/9/19.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
#define ADD(x, y) x+y

class Test {
    int a;
public:
    Test() :a(0) {cout << "void";}
    explicit Test(int i):a(i) {cout << "int" ;}
    Test(short s) : a(s) {cout << "short";}
    Test&operator = (int n) {
        a = n;
        cout << " operatro = ";
    }
};
//class A {
//public:
//    int m;
//    void print() {cout << "A\n";}
//};
//class A {virtual ~A(){}};
//class B {virtual ~B(){}};
//class C: public A, public B{};
class sam {
public:
    int num;
    void f() {cout << num;}
}x, *p = &x;
int main() {
//    int x  = 9999;
//    int res = 0;
//    while (x) {
//        res++;
//        x = x &(x-1);
//    }
//    cout << res  << endl;
//    int a = 5, b = -5;
//    cout << a % (-4) << " " << b % (-4) << endl;
//    int m = 3;
//    m += m * ADD (m ,m);
//    cout << m<< endl;

//    int n;
//    Test a = n;

//    char *a = "a+b=20\n";
//    cout << strlen(a) << endl;

//    A *pa = 0;
//    pa->print();

//    C *pc = new C();
//    A *pa = (A*)pc;
//    B *pb = (B*)pc;
//    if (pa == pc) cout << "pa == pa\n";
//    if (pb == pc) cout << "pb == pc\n";

    int a[] = {1};
    int a2[3] = {1,2};
    int a3[] = {};
    int a4[3] = {0,1,2};
    return 0;
}
