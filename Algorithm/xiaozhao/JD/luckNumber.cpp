//
// Created by BranY on 2016/9/6.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
void  getLUckNumber_2(ll n, string &res) {
    if (n <= 0) return ;
    ll prev = (n - 1) / 2;
    ll cur = n - prev * 2;
    if (n == 1) {
        res.push_back('4');
        return;
    } else if (n == 2) {
        res.push_back('7');
        return;
    } else {
        if (prev > 0) getLUckNumber_2(prev, res);
        if (cur > 0) getLUckNumber_2(cur, res);
    }
}
string getLuckNumber(int n) {
    if (n <= 0) return "";
    string res;
    int cur = 0, step, remain, prev = 0;
    for (int i = 1; cur < n; i++) {
        step = (int)pow(2, i);
        prev = cur;
        cur += step;
        remain = n - cur + step;
        if ( remain / step <= step/2) {
            if (remain % step == 1)
                res.push_back('4');
            else
                res.push_back('7');
        } else
            res.push_back('7');

    }
    return res;
}
int rand5() {

}
int rand7()
{
    int n=25;
    while(n>21){
        n=5*(rand5()-1)+rand5();
    }
    return (n%7)+1;
}
int rand10()
{
    int n=49;
    while(n>40){
        n=7*(rand7()-1)+rand7();
    }
    return n%10+1;
}
void WT(int n) {
    int count = 0;
    int t = n;
    while (1) {
        if (t == 1 && count == 9) {
            cout << n << endl;
            return;
        } else if (count == 9) break;
        if (t % 2) {
            t /= 2;
        } else
            t += 1;
        count++;
    }
}
int main() {
    int n;
    while (cin >> n) {
        string res;
        getLUckNumber_2(n, res);
        cout << res << endl;
        //cout << getLuckNumber(n) << endl;
    }
    return 0;
}
