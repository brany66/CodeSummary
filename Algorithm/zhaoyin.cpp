//
// Created by BranY on 2016/9/21.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cassert>
#include <queue>
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
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    maxHeap.push(3);
    maxHeap.push(5);
    maxHeap.push(7);
    maxHeap.push(6);
    maxHeap.push(2);
    maxHeap.push(1);
    cout << maxHeap.top() << endl;
    string s;

    return 0;
}
