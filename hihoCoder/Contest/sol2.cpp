//
// Created by wuyan on 2016/7/17.
// Contact mail wyang@smail.nju.edu.cn
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, M, count;
struct point {
    int x, y;
};
struct line {
    point p1, p2;
}query[102];

int answer[102];
int width[25];
/**
 * 每层的x坐标不变，二分查找 , 所以每层是x, y[], left to right
 * 先判断这层高度在不在，
 */
void fun(point root, int s, line l, int a) {
    //2,3象限
    if (l.p2.x < 0 || (l.p2.x == 0 && (l.p1.y < 0 || l.p1.y > 0))) return;
    if (s == N) return;
    point child[2];
    if (root.x == 0) {
        if ((root.x >= l.p1.x && root.x <= l.p2.x) && (root.y >= l.p1.y && root.y <= l.p2.y))
            count += 1;
    }
    int yy  = a;
    if (s == 1)
        a = 2;
    else
        a = 2 * yy + 1;
    child[0].x = a;
    child[0].y = 0 - a;
    child[1].x = a;
    child[1].y = a;
    if ((child[0].x >= l.p1.x && child[0].x <= l.p2.x) && (child[0].y >= l.p1.y && child[0].y <= l.p2.y)) {
        count += 1;
    }
    if ((child[1].x >= l.p1.x && child[1].x <= l.p2.x) && (child[1].y >= l.p1.y && child[1].y <= l.p2.y)) {
        count += 1;
    }
    fun(child[0], s+1, l, a);
    fun(child[1], s+1, l, a);
}
void fun1(int x, int h, int k) {
    vector<int> index;
    int i, j;
    index.clear();
    if (h == 1) {
        index.push_back(0);
    }else if (h == 2) {
        index.push_back(x);
    } else {
        index.push_back(x);
        int num = (int)pow(2, h-2);
        for (j = 1; j < num; j++) {
            if (j % 2 == 0) {
                index.push_back(index.back() - 2);
            } else {
                index.push_back(index.back() - 2 * width[k]);
            }
        }
    }
    for (i = 1; i <= M; i++) {
        if (query[i].p1.x <= x && x <= query[i].p2.x ) {
            vector<int>::const_iterator it;
            for (it = index.begin(); it != index.end(); it++) {
                int val = *it;
                if (query[i].p1.y <= val && val <= query[i].p2.y)
                    answer[i] += 1;
                if (val != 0) {
                    if (query[i].p1.y <= (-val) && (-val) <= query[i].p2.y)
                        answer[i] += 1;
                }
            }
        }
    }

}
int main()
{
    width[1] = 2;
    width[2] = 3;
    for (int j = 3; j < 25; j++)
        width[j] = 2 * width[j-1];

    while (cin >> N >> M) {
        int i, k;
        for (i = 1; i <= M; i++) {
            cin >> query[i].p1.x >> query[i].p1.y >> query[i].p2.x >> query[i].p2.y;
            answer[i] = 0;
        }
        int x  = width[N] - 1;
        for(i = N, k = 1; i >= 1; --i) {
            fun1(x, i, k);
            int tmp = x;
            x = tmp - width[k];
            k++;
        }
        for (i = 1; i <= M; i++)
            cout << answer[i] << endl;
    }
    return 0;
}
