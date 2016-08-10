//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;
int count(int n) {
    if (n < 1) return 0;
    if (n == 1) return 10;
    int res=1, i;
    for (i = 9; i >= (9 - n + 2); --i)  res *= i;
    return res * 9;
}
int countNumbersWithUniqueDigits(int n) {
    if (n < 0) return 0;
    if (n  == 0) return 1;
    int res = 0, i;
    for (i = 1; i <= n; i++) res += count(i);
    return res;
}

int permutation(int n, int r)
{
    if(r == 0) {
        return 1;
    }else{
        return n * permutation(n - 1, r - 1);
    }
}
int countNumbersWithUniqueDigits_2(int n) {
    int sum = 1;
    if(n > 0) {
        int end = (n > 10)? 10 : n;
        for(int i = 0; i < end; i++) {
            sum += 9 * permutation(9, i);
        }
    }
    return sum;
}
int main() {
    int n;
    while (cin >> n) {
        cout << countNumbersWithUniqueDigits(n) << endl;
    }
    return 0;
}