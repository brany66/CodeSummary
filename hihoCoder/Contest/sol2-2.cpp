//
// Created by BranY on 2016/7/20.
// Contact at wyang@smail.nju.edu.cn
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int treeSize[25];
int n,m;
int query[105][4];
int answer[105];
/**
 * 每层的x坐标不变，二分查找 , 所以每层是x, y[], left to right
 * 先判断这层高度在不在，
 */
void checkAll(int x, vector<int>& y ){
    for(int i = 0; i < m; i++){
        if(query[i][0] <= x && x <= query[i][2]) {

            int idx1 = lower_bound(y.begin(), y.end(), query[i][1]) - y.begin();
            int idx2 = lower_bound(y.begin(), y.end(), query[i][3]) - y.begin();
            cout << "i " << i  << " " << idx1 << " " << idx2 << " " << y.size() << endl;
            while(idx2 != y.size() && y[idx2] <= query[i][3])
                ++idx2;
            answer[i] += idx2 - idx1;
        }
    }
}

int main(){
    treeSize[1] = 2;
    treeSize[2] = 3;
    for(int i = 3;i <= 20;++i)
        treeSize[i] = treeSize[i-1]*2;

    while (cin >> n >> m) {
        for(int i = 0;i < m;i++) {
            cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];
        }
        int x = 0;
        vector<int> yNow, yLast;
        yLast.push_back(0);
        checkAll(0, yLast);
        for(int i = n-1; i >= 1; --i){
            x += treeSize[i];
            yNow.clear();
            for(int j = 0;j < yLast.size(); ++j){
                yNow.push_back(yLast[j] - treeSize[i]);
                yNow.push_back(yLast[j] + treeSize[i]);
            }
            checkAll(x, yNow);
            yNow.swap(yLast);
        }

        for(int i = 0;i < m;i++){
            cout << answer[i] << endl;
        }
    }
    return 0;
}
