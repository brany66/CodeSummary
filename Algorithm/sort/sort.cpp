//
// Created by BranY on 2016/7/30.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <cstdlib>

using namespace std;
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}
void print_2(vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] > 0)
            cout << a[i] << " ";
    cout << endl;
}
/**
 * 冒泡排序
 * @param a
 */
void bubbleSort(vector<int>& a) {
    if (a.size() <= 1) return;
    int n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n - i; j++)
            if (a[j-1] > a[j])
                swap(a[j-1], a[j]);
}
void bubbleSort_2(vector<int>& a) {
    if (a.size() <= 1) return;
    int n = a.size();
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = 1; j < n; j++)
            if (a[j-1] > a[j]) {
                swap(a[j-1], a[j]);
                flag = true;
            }
        n--;
    }
}
/**
 * 双向冒泡排序
 * @param a
 */
void cocktailSort(vector<int>& a) {
    int i, tmp;
    int left = 0, right = a.size() - 1;
    while (left < right) {
        for (i = left; i < right; i++)
            if(a[i] > a[i+1]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        right--;
        for (i = right; i > left; i++)
            if (a[i-1] > a[i]) {
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
            }
        left++;
    }
}
/**
 * 插入排序
 * @param a
 */
void insertSort(vector<int>& a) {
    int i, j, n = a.size();
    for (i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            int tmp = a[i];
            for (j = i-1; j >= 0 && a[j] > tmp; j--)
                a[j+1] = a[j];
            a[j+1] = tmp;
        }
    }
}
/**
 * 归并排序
 * @return
 */
void mergeArray(vector<int> &a, int first, int mid, int last, vector<int>& tmp) {
    int i = first, j = mid+1;
    int m = mid, n = last, k = 0;
    while (i <= m && j <= n) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= m)
        tmp[k++] = a[i++];
    while (j <= n)
        tmp[k++] = a[j++];
    for (i = 0; i < k; i++)
        a[first+i] = tmp[i];
}
void mergeSort(vector<int> &a, int first, int last, vector<int> tmp) {
    if (first < last) {
        int m = (first + last) / 2;
        mergeSort(a, first, m, tmp);
        mergeSort(a, m+1, last, tmp);
        mergeArray(a, first, m, last, tmp);
    }
}
void merge(vector<int> &a) {
    vector<int> tmp(a.size(), 0);
    mergeSort(a, 0, a.size() - 1, tmp);
}

/**
 * Bucket Sort
 * @return
 */
void bucket_sort(vector<int>& a, int maxNumber = 99)
{
    vector<int> sor(maxNumber+1, 0);
    for (int i = 0; i < a.size(); i++)
    {
        sor[a[i]] = a[i];
    }
    a.clear();
    for (int i = 0; i < sor.size(); i++) {
        if (sor[i] > 0)
            a.push_back(sor[i]);
    }
}
/**
 * 计数排序
 * @return
 */
void countSort(vector<int>& a) {
    int Max = 0, Min = INT_MIN;
    int i, n = a.size();
    for (i = 0; i < n; i++) {
        Max = max(Max, a[i]);
        Min = (Min, a[i]);
    }
    Max++;
    int *count = (int *)malloc(sizeof(int) * (Max - Min));
    int *ans = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < Max; i++) count[i] = 0; //init
    for (i = 0; i < n; i++) count[a[i] - Min]++;
    for (i = 1; i < Max; i++) count[i] += count[i-1];

    for (i = n-1; i >= 0; i--) ans[--count[a[i] - Min]] = a[i];

    for (i = 0; i < n; i++) a[i] = ans[i];
}

/**
 * 基数排序
 * 基为：10
 * @return
 */
int maxBit(vector<int>& a) {
    int d = 1;
    for(int i = 0; i < a.size(); i++) {
        int c = 1;
        int p = a[i];
        while (p/10) {
            p = p/10;
            c++;
        }
        d = max(d, c);
    }
    return d;
}
void radixSort(vector<int>& a) {
    int i, n = a.size();
    int d = maxBit(a);
    int r = 1;
    vector<int> radix(10, 0);
    for (i = 0; i < n; i++)  {
        int k = a[i] / r;
        radix[k % 10]++;
    }
    for (i = 1; i < 10; i++) radix[i] += radix[i-1];

    for (i = n-1; i>=0; i--) {
        int p = a[i] / r;
        int s = p % 10;

    }
}
int main()
{
//    int N;
//    cin >> N;
//    vector<int> num;
//    for (int i = 0; i < N; i++) {
//        int tmp;
//        cin >> tmp;
//        num.push_back(tmp);
//    }
//    //bubbleSort_2(num);
//    //insertSort(num);
//    merge(num);
//    print(num);

    vector<int> arr = {99, 65, 24, 47, 50, 88,33, 66, 67, 31, 18};
    bucket_sort(arr);
    print(arr);
    return 0;
}
