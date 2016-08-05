//
// Created by BranY on 2016/8/2.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
/**
 * [a,b] ->left:[a, (a+b)/2], right:[(a+b)/2 + 1, b]
 * rt : root
 * left: rt << 1 : l, m
 * right: rt << 1 | 1 : m+1, r
 * @return
 */
const int maxInd = 256;
int segTree[maxInd * 4 + 10];
int lazy[maxInd * 4 + 10];
int array[maxInd];

/* 对于区间求和 */
void push_up(int rt) {
    segTree[rt] = segTree[rt << 1] + segTree[rt << 1 | 1];
}

void push_up_Max(int rt) {
    segTree[rt] = max(segTree[rt << 1], segTree[rt << 1 | 1]);
}
/**
 * 对于区间求和, 原子数组值需要加上lazy标记乘以子树所统计的区间长度。
 * 则len - (len >> 1)为左子树区间长度, len >> 1为右子树区间长度。
 * @param rt
 * @param len 父节点统计的区间长度
 */
void push_down(int rt, int len) {
    segTree[rt << 1] += lazy[rt] * (len - (len >> 1));
    lazy[rt << 1] += lazy[rt];
    segTree[rt << 1 | 1] += lazy[rt] * (len >> 1);
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
}

void push_down(int rt) {
    segTree[rt << 1] += lazy[rt] ;
    lazy[rt << 1] += lazy[rt];
    segTree[rt << 1 | 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
}

void buildTree(int node, int start, int end) {
    if (start == end)
        segTree[node] = array[start];
    else {
        buildTree(2 * node, start, (start+end)/2);
        buildTree(2 * node + 1, (start+end)/2 + 1, end);

        /* 回溯得到当前结点的信息 */
        push_up_Max(node);
//        if (segTree[2*node] <= segTree[2*node + 1])
//            segTree[node] = segTree[2 * node];
//        else
//            segTree[node] = segTree[2 * node + 1];
    }
}

/**
 * 区间查询
 * @param node ： 当前查询节点
 * @param begin ：当前结点的起始
 * @param end   ：当前结点的结束
 * @param left  ：查询起始
 * @param right ：查询结束
 * @return
 */
int query(int node, int begin, int end, int left, int right) {
    int p1, p2;
    /* 两个区间不相交 */
    if (left > end || right < begin)
        return -1;
    if (begin >= left && end <= right)
        return segTree[node];
    int m = (begin + end) >> 1;
    p1 = query(2*node, begin, m, left, right);
    p2 = query(2*node +1, m+1, right, left, right);

    if (p1 == -1)
        return p2;
    if(p2 == -1)
        return p1;
    if(p1 <= p2)
        return p1;
    return p2;
}
/**
 *
 * @param p
 * @param delta
 * @param rt :root = 1
 * @param l :1
 * @param r : N
 */
void singleUpdate(int p, int delta, int rt, int l, int r) {
    if (l == r) {
        segTree[rt] += 1;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) singleUpdate(p, delta, rt << 1, l, m);
    else singleUpdate(p, delta, (rt << 1 | 1), m+1, r);
    push_up_Max(rt);
}
/**
 *
 * @param L
 * @param R
 * @param delta
 * @param rt 1
 * @param l 1
 * @param r N
 * @return
 */
void rangeUpdate(int L, int R, int delta, int rt, int l, int r) {
    if (L <= l && r <= R) {
        segTree[rt] += delta * (r - l + 1);
        lazy[rt] += delta;
        return ;
    }
    if (lazy[rt]) push_down(rt, r-l+1);
    int m = (l+r) >> 1;
    if (L <= m) rangeUpdate(L, R, delta, (rt << 1), l, m);
    if (R > m) rangeUpdate(L, R, delta, (rt << 1 | 1), m+1, r);
    push_up_Max(rt);

}
int main()
{
    array[0] = 1, array[1] = 2,array[2] = 2, array[3] = 4, array[4] = 1, array[5] = 3;
    buildTree(1, 0, 5);
    for (int i = 1; i <=20; ++i)
        cout << "seg " << i << " = " << segTree[i] << endl;
    return 0;
}
