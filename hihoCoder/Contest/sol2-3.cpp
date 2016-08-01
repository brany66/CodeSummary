//
// Created by BranY on 2016/7/21.
// Contact at wyang@smail.nju.edu.cn
//
#include <iostream>
#include <cmath>
using namespace std;
int N, M;
struct point {
    int x, y;
};
struct line {
    point p1, p2;
}query[102];
int countWidth(int h) {
    return pow(2, h + 1) - pow(2, h-1) - 1;
}
void calculateChild(int h, int x, int y, int &x_child, int &y_child, bool left) {
    int wid = countWidth(h);
    int h_y = left ? (y - wid/2) : (y + wid/2);
    int h_x = x + wid/2;
    if (h > 2) {
        int wid1 = countWidth(h-1);
        x_child = h_x - wid1/2;
        y_child = left ? (h_y + wid1/2) : (h_y - wid1/2);
    } else {
        x_child = h_x;
        y_child = h_y;
    }
}
int fun(int h, int x, int y, line l) {
    int count = 0;
    if (x > l.p2.x)
        return 0;
    int left_x, left_y, right_x, right_y;
    calculateChild(h, x, y, left_x, left_y, true);
    calculateChild(h, x, y, right_x, right_y, false);
    if ((l.p1.x <= x && x <= l.p2.x) && (l.p1.y <= y && y <= l.p2.y))
        count += 1;
    if (N > 1 ) {
        if (y <= l.p1.y)
            count += fun(h-1, right_x, right_y, l);
        else if (y >= l.p2.y)
            count += fun(h-1, left_x, left_y, l);
        else
            count += fun(h-1, left_x, left_y, l) + fun(h-1, right_x, right_y, l);
    }
    return count;
}

int main()
{
    while (cin >> N >> M) {
        int i;
        for (i = 1; i <= M; i++) {
            cin >> query[i].p1.x >> query[i].p1.y >> query[i].p2.x >> query[i].p2.y;
        }
        for (i = 1; i <=M; i++)
            cout << fun(N, 0, 0, query[i]) << endl;
    }
    return 0;
}
