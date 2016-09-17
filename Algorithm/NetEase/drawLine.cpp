//
// Created by BranY on 2016/9/17.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// http://hihocoder.com/contest/ntest2016spring1/problems

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int maxn = 100000 + 5;
int n;
struct Point {
    int x, y;
    Point (int _x = 0, int _y = 0) :x(_x), y(_y) { }

    bool operator < (const Point & b) const { //在右边或位于正上方
        return x < b.x || (x == b.x && y < b.y);
    }
};

typedef pair<Point, Point> Segment;

vector<Segment> segments[4];

int judgeSegment(const Point & a, const Point & b) {
    if (a.y == b.y) return 0;       //水平
    else if (a.x == b.x) return 1;  //垂直
    else if (a.y < b.y) return 2;   //正45
    else return 3;                  //反45
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < 4; ++i) segments[i].clear();
    for (int i = 0; i < n; ++i) {  //N行，N个线段
        Point a, b;
        scanf("%d%d", &a.x, &a.y);
        scanf("%d%d", &b.x, &b.y);
        if (a.x > b.x || (a.x == b.x && a.y > b.y)) swap(a, b); //使b始终在a的右边和上边
        int type = judgeSegment(a, b);
        segments[type].push_back(make_pair(a, b)); //按线段类型分4类
    }
}

int countSegment(vector<pair<int, int>>  lrPairs) {
    int res = 0;
    sort(lrPairs.begin(), lrPairs.end());
    int pre = -1e9;
    for (auto lrPair : lrPairs) {
        if (lrPair.first > pre) ++res;
        pre = max(pre, lrPair.second);
    }
    return res;
}

int countHorizontal(vector<Segment> horizontal) { //水平
    map<int, vector<pair<int, int>>> div; //按y
    for (auto seg : horizontal) { //循环
        int y = seg.first.y;
        div[y].push_back(make_pair(seg.first.x, seg.second.x)); //y相同的全部存在div对应键值的vector中
    }

    int res = 0;
    for (const auto & lrPairs : div) {
        res += countSegment(lrPairs.second);
    }
    return res;
}

int countXie(vector<Segment> xie) {
    map<int, vector<pair<int, int>>> div;
    for (auto seg : xie) {
        int C = seg.first.y - seg.first.x;
        div[C].push_back(make_pair(seg.first.x, seg.second.x));
    }

    int res = 0;
    for (const auto & lrPairs : div) { //针对每条直线，判断重合的线段
        res += countSegment(lrPairs.second);
    }
    return res;
}

void solve() {
    int ans = 0;
    ans += countHorizontal(segments[0]);  //水平

    for (auto seg : segments[1]) {        //交换y和x之后，可以调用水平的统计函数
        swap(seg.first.x, seg.first.y);
        swap(seg.second.x, seg.second.y);
    }

    ans += countHorizontal(segments[1]);  //垂直

    ans += countXie(segments[2]); //正45°

    for (auto & seg : segments[3]) {   //负45°
        seg.first.x = -seg.first.x;    //将方向反转
        seg.second.x = -seg.second.x;
        if (seg.first.x > seg.second.x) swap(seg.first, seg.second);
    }
    ans += countXie(segments[3]);
    printf("%d\n", ans);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        input();
        solve();
    }
    return 0;
}
