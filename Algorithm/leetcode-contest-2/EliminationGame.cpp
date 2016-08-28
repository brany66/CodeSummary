//
// Created by BranY on 2016/8/28.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int lastRemaining(int n) {
    if (n == 1) return 1;
    deque<int> que;
    int i;
    for (i = 0; i < n; i++) {
        que.push_back(i + 1);
    }
    bool flag = true;
    while (que.size() >= 1) {
        if (que.size() == 1) return que.front();
        vector<int> tmp;
        if (flag) {
            while (!que.empty()) {
                que.pop_front();
                if (!que.empty()) {
                    tmp.emplace_back(que.front());
                    que.pop_front();
                }
            }
            if (tmp.size() == 1) return tmp[0];
            for (int i = 0; i < tmp.size(); i++)
                que.push_back(tmp[i]);
        } else{
            //que.pop_back();
            while (!que.empty()) {
                que.pop_back();
                if (!que.empty()) {
                    int k = que.back();
                    tmp.emplace_back(k);
                    que.pop_back();
                }
            }
            if (tmp.size() == 1) return tmp[0];
            for (int i = tmp.size() - 1; i >= 0; --i)
                que.push_back(tmp[i]);
        }
        i = flag ? 0 : tmp.size() - 1;
        flag = !flag;
    }
    return 0;
}
int lastRemaining1(int n) {
    if (n == 1) return 1;
    int count = n;
    int start = 1;
    int end = n;
    int offset = 2;
    bool flag = true;
    while (count > 0) {
        if (flag) {
            int i = start;
            while (i <= end) {
                i += offset;
                --count;
            }
            if ((i - offset) == end){
                end -= offset/2;
            }
            start += offset/2;
        } else {
            int i = end;
            while (i >= start) {
                i -= offset;
                --count;
            }
            end -= offset/2;
            if (i + offset == start) start += offset/2;
        }
        if (count == 1) {
            return flag ? start : end;
        }
        flag = !flag;
        offset *= 2;
    }
    return (!flag) ? start : end;
}
int lastRemaining_2(int n) {
    if (n == 1) return 1;
    int cnt = n;
    int begin = 1;
    int offset = 2;
    while (cnt > 0) {
        cnt -= (cnt % 2 == 0) ? cnt/2 : (cnt/2 + 1);
        begin += offset/2;
        offset *= 2;
        cnt -= (cnt % 2 == 0) ? cnt/2 : (cnt/2 + 1);
    }
}
int main() {
    int n;
    while (cin >> n) {
        cout << lastRemaining1(n) << " ";
        cout << lastRemaining_2(n) << endl;
        cout << "****************************************\n";
    }
    return 0;
}
