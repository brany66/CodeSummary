//
// Created by BranY on 2016/9/3.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
/**
 * Time Complexicity O(n), Space Complexicity O(n)
 * 从上面的例子我们能看到，前n个元素中，
 * 第1个元素a1到了原第2个元素a2的位置，即1->2；
 * 第2个元素a2到了原第4个元素a4的位置，即2->4；
 * 第3个元素a3到了原第6个元素b2的位置，即3->6；
 * 第4个元素a4到了原第8个元素b4的位置，即4->8；
 * 那么推广到一般情况即是：前n个元素中，第i个元素去了 第（2 * i）的位置。
 *
 * 上面是针对前n个元素，那么针对后n个元素，可以看出：
 * 第5个元素b1到了原第1个元素a1的位置，即5->1；
 * 第6个元素b2到了原第3个元素a3的位置，即6->3；
 * 第7个元素b3到了原第5个元素b1的位置，即7->5；
 * 第8个元素b4到了原第7个元素b3的位置，即8->7；
 * 推广到一般情况是，后n个元素，第i个元素去了第 (2 * (i - n) ) - 1 = 2 * i - (2 * n + 1) = (2 * i) % (2 * n + 1) 个位置。
 * 再综合到任意情况，任意的第i个元素，我们最终换到了 (2 * i) % (2 * n + 1)的位置。为何呢？因为：
 * 当0 < i < n时， 原式= (2i) % (2 * n + 1) = 2i；
 * 当i > n时，原式(2 * i) % (2 * n + 1)保持不变。
 */
void perfect_shuffle(vector<int> &nums, int n) {
    int n2 = n * 2;
    vector<int> b(n2+1, 0);
    for (int i = 1; i<= n2; ++i) {
        b[(2 * i) % (n2 + 1)] = nums[i];
    }
    for (int i = 1; i <= n2; i++)
        nums[i] = b[i];
}
/**
 * 1->2->4->7->8->5->1
 * 3->6->3
 * 原始数组：1 2 3 4 5 6 7 8 数组下标：1 2 3 4 5 6 7 8
 * 走第一圈：5 1 3 2 7 6 8 4 走第二圈：5 1 6 2 7 3 8 4
 * @return
 */

void cycleLeader(vector<int> &nums, int from, int mod) {
    int t, i;
    for (i = from * 2 % mod; i != from; i = i * 2 % mod) {
        t = nums[i];
        nums[i] = nums[from];
        nums[from] = t;
    }
}

void reverseArray(vector<int> &nums, int from, int to) {
    int t;
    while (from < to) {
        t = nums[from];
        nums[from] = nums[to];
        nums[t] = t;
        ++from;
        --to;
    }
}
void rightRotate(vector<int>&nums, int num, int n) {
    reverseArray(nums, 1, n - num);
    reverseArray(nums, n - num + 1, n);
    reverseArray(nums, 1, n);
}

/**
 * 神级结论：若2*n=（3^k - 1），则可确定圈的个数及各自头部的起始位置
 *
 * 输入数组　A[1..2 * n]
 * step 1 找到 2 * m = 3^k - 1 使得 3^k <= 2 * n < 3^(k +1)
 * step 2 把a[m + 1..n + m]那部分循环移m位
 * step 3 对每个i = 0,1,2..k - 1，3^i是个圈的头部，做cycle_leader算法，数组长度为m，所以对2 * m + 1取模。
 * step 4 对数组的后面部分A[2 * m + 1.. 2 * n]继续使用本算法, 这相当于n减小了m。
 */
void perfectShuffle_3(vector<int>& nums, int n) {
    int n2, m, i, k, t;
    for (; n > 1;) {
        // step 1
        n2 = n * 2;
        for (k = 0, m = 1; n2 / m >= 3; ++k, m *= 3)
            ;
        m /= 2;
        // 2m = 3^k - 1 , 3^k <= 2n < 3^(k + 1)

        // step 2
        //rightRotate(nums + m, m, n);

        // step 3
        for (i = 0, t = 1; i < k; ++i, t *= 3)
        {
            cycleLeader(nums , t, m * 2 + 1);
        }

        //step 4
       // nums += m * 2;
        n -= m;

    }
}
int main() {
    vector<int> nums(53, 0);
    for (int i = 1; i <= 52; i++) {
        nums[i] = i;
    }
    perfect_shuffle(nums, 26);
    for (int i = 1; i <= 52; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
