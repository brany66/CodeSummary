//
// Created by BranY on 2016/8/11.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
/**
 * 计算v的二进制中1个数
 * @param v
 * @return
 */
int countOneBitNum(int v) {
    int sum = 0;
    while (v) {
        v &= (v-1);
        sum++;
    }
    return sum;
}
int main() {
    int n;
    while (cin >> n) {
        cout << countOneBitNum(n) << endl;
    }
    return 0;
}