//
// Created by BranY on 2016/7/20.
// Contact at wyang@smail.nju.edu.cn
//

#include <iostream>
#include <algorithm>
using namespace std;
bool cmp (int a, int b) {
    return a < b;
}

bool cmp2 (int a , int b) {
    return a <= b;
}
/**
 * lower_bound() value：最早可以插入的位置
 * upper_bound()
 */
int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    cout << int(lower_bound(a, a+10, 2, cmp) - a) << "  " << int(lower_bound(a, a+10, 2) - a) << endl;

    cout << int(upper_bound(a, a+10, 2, cmp) - a) << " " << int(upper_bound(a, a+10, 2) - a) << endl;

    cout << int(lower_bound(a, a+10, 2, cmp2) - a) << "  " << int(lower_bound(a, a+10, 2) - a) << endl;

    cout << int(upper_bound(a, a+10, 2, cmp2) - a) << " " << int(upper_bound(a, a+10, 2) - a) << endl;

    int x = 0;
    cout << x  << " " << -x << endl;
    return 0;
}