//
// Created by BranY on 2016/9/10.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
class ClassA
{
public:
    virtual ~ ClassA(){};
    virtual void FunctionA(){};
};
class ClassB
{
public:
    virtual void FunctionB(){};
};
class ClassC : public ClassA,public ClassB
{
public:
};
int main() {
    ClassC aObject;
    ClassA* pA=&aObject;
    ClassB* pB=&aObject;
    ClassC* pC=&aObject;

    cout << "pA " << pA << endl;
    cout << "pB " << pB << endl;
    cout << "pC " << pC << endl;

    //int px*;
    char *acp[10];
    char (*pac) [10];
    int(*p) ();
    return 0;
}
