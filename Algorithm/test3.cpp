//
// Created by BranY on 2016/8/14.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
long long  numTrees(int n) {
    if (n <= 0) return 0;
    long long  part1 = 1, part2 = 1;
    int i;
    for (i = 2 * n; i > 1; --i) part1 *= i;
    for (i = n; i > 1; --i) part2 *= i;
    part1 /= part2;
    part1 /= part2;
    part1 /= n+1;
    return part1;
}
int numTrees_2(int n) {
    if(n <= 0){
        return 0;
    }
    vector<int> f(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            f[i] += f[j - 1] * f[i - j];
        }
    }
    return f[n];
}


int result[25001];
void sovle(int n)
{
    int i,j,len,carry,current;
    result[0] = 1;
    len = 1;
    for (i = 2;i <= n; i++) {
        carry = 0;
        for (j = 0;j < len; j++) {
            current = result[j];
            result[j] = (i*current+carry)%10;
            carry = (current*i+carry)/10;
        }
        while (carry>0){
            current = carry;
            carry = current/10;
            result[len] = current%10;
            len++;
        }
    }

    for (i = len-1;i >= 0; --i){
        cout << result[i];
    }
    cout << endl;
}
int main() {
    int N;
    while (cin >> N) {
        cout << numTrees(N) << "   " << numTrees_2(N)<< endl;
    }
    return 0;
}

