//
// Created by BranY on 2016/8/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
class A
{
    int a;
    short b;
    int c;
    char d;
};
class B
{
    double a;
    short b;
    int c;
    char d;
};
class C
{
    int i;
    union U
    {
        char buff[13];
        int i;
    }u;
    //void foo() {    }
    typedef char* (*f)(void*);
    enum{red, green, blue} color;
}aa;

char* f(char *str, char ch) {
    char *it1 = str;
    char *it2 = str;
    while (*it2 != '\0') {
        while (*it2 == ch) { it2++; }
        *it1++ = *it2++;
    }
    return str;
}

int main() {
    int a = 3;
    a += a -= a*a;
    cout << a << endl;
    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(aa) << endl;

    char *aaaa = new char[10];
    strcpy(aaaa, "abcdcccd");
    cout << f(aaaa, 'c') << endl;
    return 0;
}
