//
// Created by BranY on 2016/8/22.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int lengthLongestPath(string input) {
    istringstream ss(input);
    string token;
    size_t max_len = 0;
    unordered_map<int, int> path_len;
    path_len[0] = 0;
    while (getline(ss, token)) {
        auto pos = token.find_last_of("\t");
        string name = (pos != std::string::npos) ? token.substr(pos + 1) : token;

        int depth = token.size() - name.size();
        if (token.find(".") != std::string::npos) {
            max_len = max(max_len, path_len[depth] + name.size());
        } else {
            path_len[depth + 1] = path_len[depth] + name.size() + 1;
        }
    }
    return max_len;
}
int main() {
    string str;
    while (getline(cin, str)) {
        cout << str << endl;
        cout << str.find_last_of("\t") << endl;
        //cout << lengthLongestPath(str) << endl;
    }
    return 0;
}
