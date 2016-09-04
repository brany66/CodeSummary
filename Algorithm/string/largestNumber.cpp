//
// Created by BranY on 2016/9/3.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
struct comp {
    bool operator()(const string& a, const string& b){
        int sza = a.size(), szb = b.size() , i = 0;
        for ( i = 0; i < sza && i < szb; ++i ) {
            if ( a[i] < b[i] ) return true;
            else if ( a[i] > b[i] ) return false;
        }
        if ( i < sza ) {
            return (a.substr( i ) + b) < a;
        }
        if ( i < szb ) {
            return b < (b.substr( i ) + a);
        }
        return false;
    }
};
bool comp1(const string s1, const string s2) {
    return (s1 + s2) < (s2 + s1);
}
string getLargest(vector<int> &nums) {

    vector<string> str_nums(nums.size());
    for(int i = 0; i < nums.size(); ++i) {
        stringstream ss;
        ss << nums[i];
        str_nums[i] = ss.str();
    }

    // sort the string as the way we want
    sort(str_nums.begin(), str_nums.end(), comp1);
    for (auto c: str_nums)
        cout << c << " " ;
    cout << endl;

    string res;
    for(int i = str_nums.size() - 1; i >= 0; --i)
        res += str_nums[i];
    // if the first character is ’0‘，this must be '0', no matter how many character behind
    if(res[0]=='0') return string("0");
    return res;
}
int main() {
    vector<int> num = {3, 30, 34, 5, 9};
    string res = getLargest(num);
    cout << res << endl;
    return 0;
}
