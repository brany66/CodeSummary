//
// Created by BranY on 2016/9/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            long N, M, a, c, d;
            cin >> N >> M >> a;
            c = N / a;
            d = M / a;
            if (N % a != 0) ++c;
            if (M % a != 0) ++d;
            cout << c * d << endl;
        }
    }
    return 0;
}
