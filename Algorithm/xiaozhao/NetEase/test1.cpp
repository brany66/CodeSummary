//
// Created by BranY on 2016/9/18.
// Contact at wyang@smail.nju.edu.cn
// Copyright(c) 2016 NJU PASA Lab All rights reserved.
//
#include <iostream>
using namespace std;
int dfs(string &str, int k){
   int n = str.size();
    int i= 0, max_len = 0, count =0;
    bool flag = false;
    while (i < n){
        if (str[i] == '0'){
            if (!flag){
                count = 1;
                flag = true;
            } else
                count += 1;
        } else{
            max_len = max(count, max_len);
            flag = false;
        }
        i += 1;
    }
    return max_len;
}
int main() {
    int t;
    while(cin >> t) {
        int k;
        cin >> k;
        string str;
        cin.get();
        getline(cin, str);
        int i = 0, max_len =0;
        while (i < str.size() - k + 1){
            for (int j = 0; j < k;j++) {
                str[i+j] ^=1;
            }
            int cur= dfs(str, k);
            max_len = max(cur, max_len);
            i++;
        }
        cin.get();
        cout << max_len << endl;
    }
    return 0;
}

