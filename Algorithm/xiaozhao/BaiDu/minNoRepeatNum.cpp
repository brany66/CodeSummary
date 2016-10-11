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

class animal
{
protected:
    int age;
public:
    virtual void print_age(void) = 0;
};
class dog : public animal
{
public:
    dog() {this -> age = 2;}
    ~dog() { }
    virtual void print_age(void)
    {
        cout<<"Wang, my age = "<<this -> age<<endl;
    }
};
class cat: public animal
{
public:
    cat() {this -> age = 1;}     ~cat() { }
    virtual void print_age(void)
    {
        cout<<"Miao, my age = "<<this -> age<<endl;
    }
};
int main() {
    int n;
    http://www.taobao.com
    cout << "welcome to taobao" << endl;
    //cout << (93&-8) << endl;
    cout << "A " << sizeof(A) << " B " << sizeof(B) <<
         " C " << sizeof(C) << " D " << sizeof(D) << endl;

    return 0;
}
