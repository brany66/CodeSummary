//
// Created by BranY on 2016/8/21.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/contest/1/problems/lexicographical-numbers/

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
vector<int> lexicalOrder(int n) {
    vector<int> res;
    if (n <= 0) return res;
    int count = 0, k = 1;
    while (count < n) {
        if (k > n) {
            k /= 10;
            while (k % 10 == 9) k /= 10;
            k++;
        } else {
            res.push_back(k);
            count++;
            k *= 10;
        }
    }
    return res;
}
class A
{
public:
    void f()
    {
        printf("A\n");
    }
};

class B: public A
{
public:
    virtual void f()
    {
        printf("B\n");
    }
};
int main() {
    A *a = new B;
    a->f();
    delete a;
    int m=5;
    if(m++>5)cout<<m<<endl;
    else cout<<--m;


    int n;
    while (cin >> n ) {
        vector<int> res = lexicalOrder(n);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl << res.size() << endl;
    }
    return 0;
}
