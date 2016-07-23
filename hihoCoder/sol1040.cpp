//
// Created by wuyan on 2016/7/16.
// Contact mail wyang@smail.nju.edu.cn
//
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct point
{
    int x, y;
    bool operator < (const point& p2) const
    {
        if(x<p2.x||(x==p2.x&&y<=p2.y)) return true;
        return false;
    }
    bool operator == (const point& p2) const
    {
        return (x==p2.x&&y==p2.y);
    }
};

struct line
{
    point p1, p2;
    bool operator == (const line& l2) const {
        return ((p1 == l2.p1 && p2 == l2.p2) || (p1 == l2.p2 && p2 == l2.p1));
    }
};

int judgePoint(line *l)
{
    set<point> s;
    for(int i = 0; i < 4; i++)
    {
        s.insert(l[i].p1);
        s.insert(l[i].p2);
    }
    return (s.size() == 4);
}

int judgeRect(line *l)
{
    for(int i = 1; i < 4; ++i)
    {
        if((l[0].p1.y-l[0].p2.y)*(l[i].p1.y-l[i].p2.y) == -(l[0].p1.x-l[0].p2.x)*(l[i].p1.x-l[i].p2.x))
            continue;
        if((l[0].p1.y-l[0].p2.y)*(l[i].p1.x-l[i].p2.x) == (l[0].p1.x-l[0].p2.x)*(l[i].p1.y-l[i].p2.y))
            continue;
        return false;
    }
    return true;
}
int judgeRect1(line *l){
    line l11,l12,l21,l22;
    l11.p1 = l[0].p1; l11.p2 = l[1].p1;
    l12.p1 = l[1].p1; l12.p2 = l[0].p1;
    l21.p1 = l[0].p2; l21.p2 = l[1].p2;
    l22.p1 = l[1].p2; l22.p2 = l[0].p2;
    if (l[2].p1 == l[0].p1 || l[2].p1 == l[1].p1) {
        if (!(l11 == l[2] || l12 == l[2]))
            return 0;
    } else {
        if (!(l21 == l[2] || l22 == l[2]))
            return 0;
    }
    if (l[3].p1 == l[0].p1 || l[3].p1 == l[1].p1) {
        if (!(l11 == l[3] || l12 == l[3]))
            return 0;
    } else {
        if (!(l21 == l[3] || l22 == l[3]))
            return 0;
    }
    return 1;
}
int main()
{
    line l[4];
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for(int i=0; i<4; i++)
            scanf("%d %d %d %d", &l[i].p1.x, &l[i].p1.y, &l[i].p2.x, &l[i].p2.y);
        int flag = 0;
        if(judgePoint(l) && judgeRect1(l)) flag = 1;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}