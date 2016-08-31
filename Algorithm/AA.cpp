//
// Created by BranY on 2016/8/31.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
class A {
public :
    bool isTrue;
    int num;
};
int main() {
    A a;
    if (a.isTrue)
        cout << a.num << endl;
    return 0;
}
