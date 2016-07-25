//
// Created by BranY on 2016/7/23.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/problemset/problem/1037
/**
 * 小Ho选择的迷宫是一个被称为“数字三角形”的n(n不超过200)层迷宫，这个迷宫的第i层有i个房间，分别编号为1..i。
 * 除去最后一层的房间，每一个房间都会有一些通往下一层的房间的楼梯，用符号来表示的话，
 * 就是从第i层的编号为j的房间出发会有两条路，一条通向第i+1层的编号为j的房间，另一条会通向第i+1层的编号为j+1的房间，
 * 而最后一层的所有房间都只有一条离开迷宫的道路。这样的道路都是单向的，
 * 也就是说当沿着这些道路前往下一层的房间或者离开迷宫之后，小Ho没有办法再次回到这个房间。迷宫里同时只会有一个参与者，
 * 而在每个参与者进入这个迷宫的时候，每个房间里都会生成一定数量的奖券，这些奖券可以在通过迷宫之后兑换各种奖品。
 * 小Ho的起点在第1层的编号为1的房间，现在小Ho悄悄向其他参与者弄清楚了每个房间里的奖券数量，
 * 希望小Hi帮他计算出他最多能获得多少奖券。
 */
#include <iostream>
#include <limits.h>
using namespace std;
int ceil[105][105];
int best[105][105];
/**
 * 深度优先搜索 && 宽度优先遍历
 * <i, j, k>表示到达第i行的第j个房间，当前获得的奖券数为k这样一个状态
 * rewards(i, j)表示第i层第j个房间中的奖券数，那么遍历方式就是利用一个队列.
 * 先将ə, 1, rewards(1, 1)>这个状态放入队列中。然后每次取出队首<i, j, k>，如果i==n，就用k更新Ans
 * 不然就将它代表的房间所能到达的两个房间的状态<i + 1, j, k + rewards(i + 1, j)>和<i + 1, j + 1, k + rewards(i + 1, j + 1)>放入队尾，
 * 直到整个队列清空，这时候Ans就是我们要的答案。
 * best[i][j]表示达到i层j房间是获得的奖券的最大值
 * 达到第i层第j房间的路径只有两条：best[i-1][j-1] 和 best[i-1][j]
 */
int findBest(int n) {
    int ans = INT_MIN;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j<=i; j++) {
            best[i][j] = max(best[i - 1][j - 1], best[i - 1][j]) + ceil[i][j];
            if (ans < best[i][j])
                ans = best[i][j];
        }
    return ans;
}
int main()
{
    int n;
    while (cin >> n) {
        int i, j;
        for (i =1; i <= n; i++)
            for (j = 1; j <= i; j++)
                cin >> ceil[i][j];
        cout << findBest(n) << endl;
    }
    return 0;
}

