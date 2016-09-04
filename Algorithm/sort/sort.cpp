//
// Created by BranY on 2016/7/30.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <cstdlib>
#include <set>

using namespace std;
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void Swap(vector<int>& a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
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
 * https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
 * 基为：10
 * @return
 */
void radixSort(vector<int>& a) {
    int i, n = a.size();
    int Max = 0;
    for (i = 0; i < n; i++) {
        Max = max(Max, a[i]);
    }
    int r = 1;
    int *ans = (int *)malloc(sizeof(int) * n);
    while (r < Max) {
        vector<int> radix(10, 0);
        for (i = 0; i < n; i++)  {
            int k = a[i] / r;
            radix[k % 10]++;
        }
        for (i = 1; i < 10; i++) radix[i] += radix[i-1];

        for (i = n-1; i >= 0; i--)  {
            int k = a[i] / r;
            ans[--radix[k % 10]] = a[i];
        }
        for (i = 0; i < n; i++) a[i] = ans[i];
        r *= 10;
    }
}
/**
 * 选择排序
 */
void selectSort(vector<int>& a) {
    int i, j, minIndex;
    for (i = 0; i < a.size(); i++) {
        minIndex = i;
        for (j = i + 1; j < a.size(); j++)
            if (a[j] < a[minIndex])
                minIndex = j;
        swap(a[i], a[minIndex]);
    }
}
/**
 * shell Sort
 */
void shellSort(vector<int>& a) {
    int j, gap;
    for (gap = a.size() / 2; gap > 0; gap /= 2) {
        for (j = gap; j < a.size(); j++) {
            if (a[j] < a[j-gap]) {
                int tmp = a[j];
                int k = j - gap;
                while (k >= 0 && a[k] > tmp) {
                    a[k+gap] = a[k];
                    k -= gap;
                }
                a[k+gap] = tmp;
            }
        }
    }
}
/**
 * 堆排序
 * 1. 父节点的值 大于等于(或小于等于) 任何一个子节点的值
 * 2. 每个节点的左子树和右子树都是一个二叉堆
 * 3. 插入在底层，删除总是在根节点，从底层最右端选一个，然后恢复。
 * @return
 */

void fitToHeap(vector<int>& a, int l, int r) {
    int i = l;
    int tmp = a[i];
    int j = 2 * i + 1;
    while (j < r) {
        if (j+1 < r && a[j+1] > a[j]) j++;

        if (a[j] <= tmp) break; //
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = tmp;
}
void heapSort(vector<int>& a) {
    int n = a.size();
    for (int j = n/2 - 1; j >= 0; j--)
        fitToHeap(a, j, n);

    for (int i = n - 1; i >= 0; i--) {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        fitToHeap(a, 0, i);
    }
}

/**
 * quick sort
 * @return
 */
void quickSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int i = l, j = r;
        int pivot = a[i];

        while (i < j) {
            //right to left
            while (i < j && a[j] >= pivot) j--;
            if (i < j) {
                a[i] = a[j];
                i++;
            }

            //left to right
            while (i < j && a[i] < pivot) i++;
            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = pivot;
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, r);
    }
}
void quickHelp(vector<int>& a) {
    if (a.size() <= 1) return ;
    int l = 0, r = a.size();
    quickSort(a, l, r);
}

int maxSubSubMatrix(vector<vector<int>> &matrix, int k) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> sum(m, 0);
            for (int k = 0; k < m; k++) sum[k] += matrix[k][j];
            int curSum = 0, curMax = INT_MIN;
            set<int> s;
            s.insert(0);
            for (auto a: sum) {
                curSum += a;
                auto it = s.lower_bound(curSum - k);
                if (it != s.end()) curMax = max(curMax, curSum - *it);
                s.insert(curSum);
            }
            res = max(res, curMax);
        }
    }
    return res;
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

//    vector<int> arr = {99, 65, 24, 47, 50, 88,33, 66, 67, 31, 18};
//    bucket_sort(arr);
//    print(arr);

    vector<int> arr1 = {820, 631, 892, 841, 742, 251, 9, 642, 645, 896, 996,
                        938, 80, 691, 8, 785, 393, 707, 124, 67, 116, 362, 84, 104, 39, 500, 608, 740, 543};
    //quickHelp(arr1);
    radixSort(arr1);
    print(arr1);

    vector<int> arr2 = {8, 13, 0, 3, 20, 16, 9, 7, 11, 5};
    heapSort(arr2);
   // quickHelp(arr2);
    //shellSort(arr2);
    print(arr2);
    return 0;
}
