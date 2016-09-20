//
// Created by BranY on 2016/9/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
  // vector<int> dis;
    int a, cnt = 0;
    int pack = N;
    for (int i = 0; i <= M; i++) {
        cin >> a;
        if (pack >= a) {
            pack -= a;
        } else if (N >= a) {
            pack = N- a;
            ++cnt;
        }else {
            cout << 0 << endl;
        }
       // dis.push_back(a);
    }
    cout << cnt << endl;
//    int res = 0, i = 0;
//    while (i  <=  M) {
//        int sum = 0;
//        if (dis[i] > N) {
//            cout << 0 << endl;
//            break;
//        }
//        while (i <= M && sum + dis[i] <= N) {
//            sum += dis[i];
//            i++;
//        }
//        if (i == M + 1 && sum <= N) break;
//        ++res;
//    }
//    cout << res << endl;
    return 0;
}
