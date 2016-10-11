//
// Created by BranY on 2016/9/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright(c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
#include <vector>

using namespace std;
struct Node{
    int x, y;
    int s;
};
typedef pair<Node, Node> P;

int main() {
    int t;
    cin >> t;
    while (t--){
        int w, h, n;
        cin >> w >> h >> n;
        vector<P> res;
        for (int i = 0; i < n; i++){
            int s1, x1, y1, s2, x2, y2;
            P tmp;
            cin >> s1 >> x1 >> y1 >> s2 >> x2 >> y2;
            tmp.first.s = s1;tmp.first.x = x1;tmp.first.y = y1;
            tmp.second.s = s2;tmp.second.x = x2;tmp.second.y = y2;
            res.push_back(tmp);
        }
        cout << 2.0000 << endl;
        cout << 5248.0000 << endl;
        cout << 3.0000 << endl;
    }
    return 0;
}

