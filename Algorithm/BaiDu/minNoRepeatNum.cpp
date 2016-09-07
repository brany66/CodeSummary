//
// Created by BranY on 2016/9/7.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int minNoRepeatNum(int n) {
    if (n <= 0) return -1;
    vector<int> index(10, -1);
    vector<int> bit(20, 0);
    bool flag = false;
    int k = n, len = 0;
    while (k) {
        bit[len++] = k % 10;
        k /= 10;
    }
    while(true) {
        int t = n + 1;
    }
}
class A{

};
class B : virtual public A{

};
class C : virtual public A {

};
class D: public B, public C{

};
int main() {
    int n;
    http://www.taobao.com
    cout << "welcome to taobao" << endl;
    //cout << (93&-8) << endl;
    cout << "A " << sizeof(A) << " B " << sizeof(B) <<
         " C " << sizeof(C) << " D " << sizeof(D) << endl;
    while (cin >> n) {

    }
    return 0;
}
