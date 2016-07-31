//
// Created by BranY on 2016/7/31.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}
void select_1(vector<int>& prime, int N) {
    vector<bool> flag(N, false);
    int i, j;
    for (i =2; i < N; i++) {
        if (!flag[i]) {
            prime.push_back(i);
            for (j = i; j < N; j += i)
                flag[j] = true;
        }
    }
}
/**
 * 估计prime大小
 * @param prime
 * @param N
 */
void select_2(vector<int>& prime, int N) {
    vector<bool> flag(N, false);
    int i, j;
    int pi = 0;
    for (i =2; i < N; i++) {
        if (!flag[i]) {
            prime[pi++] = i;
            for (j = 0; (j < pi) && (i * prime[j] < N); j ++) {
                flag[i * prime[j]] = true;
                if ( i % prime[j] == 0) break;
            }
        }
    }
}
int main()
{
    return 0;
}