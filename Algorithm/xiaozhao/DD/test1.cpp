//
// Created by BranY on 2016/9/18.
// Cantact at wyang@smail.nju.edu.cn
// Copyright(c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
using namespace std;
int countZeros(int n){
    if (n <= 4) return 0;
    int count =0;
    for (long i = 5; n / i >= 1; i *= 5){
        count += n / i;
    }
    return count;
}
int main() {
    int n;
    while (cin >> n) {
        cout << countZeros(n) << endl;
    }
    return 0;
}

