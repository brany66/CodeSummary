//
// Created by BranY on 2016/7/31.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <time.h>

using namespace std;
void swap(int &a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
/**
 * 从大小为n的数组中，找出至少一个重复元素，里面的数属于[0,n-1];
 * O(1) Space Complexity
 * @return
 */
int findRepeatOne(vector<int>& a) {
    int i;
    for (i = 0; i < a.size(); i++) {
        while (i != a[i]) {
            if (a[i] == a[a[i]])
                return a[i];
            swap(a[i], a[a[i]]);
        }
    }
    return -1;
}

int findRepeatOne_add(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int index = a[i] >= n ? a[i] - n : a[i];
        if (a[index] >= n)
            return index;
        else
            a[index] += n;
    }
    return -1;
}

/**
 * 随机生成和为S的N个整数
 * 在区间[S, E)上随机取n个数存入A[]中
 * @return
 */
void getRandom(vector<int>& a, int N, int S, int E) {
    std::set<int> set;
    srand(time(NULL));
    for (int i = E - N; i < E; i++) {
        int num = (rand() % i) + S;
        if (set.find(num) == set.end())
            set.insert(num);
        else
            set.insert(i);
    }
    std::set<int>::iterator pos;
    for(pos = set.begin(); pos != set.end(); pos++)
        a.push_back(*pos);
}

/**
 * 数组a[N], -->b[N], 其中b[j] = a[0] * .. * a[N-1] / a[j]
 * @return
 */
void fun(vector<int>& A, vector<int>& B) {
    B[0] = 1;
    int i, n = A.size();
    for (i = 1; i < n; i++)
        B[i] = B[i-1] * A[i-1];
    int tmp = 1;
    for (i = n-2; i >= 0; i--) {
        tmp *= A[i+1];
        B[i] *= tmp;
    }
}

/**
 * 数组中每个元素相邻的绝对值差为1， 找数
 * @return
 */
int findNum(vector<int>& a, int val) {
    int next_index = abs(val - a[0]);
    while (next_index < a.size()) {
        if (a[next_index] == val)
            return next_index;
        next_index += abs(val - a[next_index]);
    }
    return -1;
}
/**
 * 给定一个无序的数组，找出第一个大于0，不在这个数组中的数
 * @return
 */
int findNotIn(vector<int>& a) {
    int i, n = a.size();
    for (i = 0; i < n; i++)
        while(a[i] > 0 && a[i] <= n && a[i] != i+1 && a[i] != a[a[i] - 1])
            swap(a[i], a[a[i] -1]);
    for (i = 0; i < n; i++)
        if (a[i] != i+1)
            break;
    return i+1;
}
int main()
{
    vector<int> test{2,4,1,5,7,6,1,9,0,2};
    string str(10, ' ');
    cout << findRepeatOne_add(test) << endl;
    return 0;
}