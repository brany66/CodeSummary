//
// Created by BranY on 2016/9/1.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (words.size() == 0) return res;

    unordered_map<string, int> hash;
    for (int i = 0; i < words.size(); i++) {
        if (hash.find(words[i]) == hash.end()) {
            hash[words[i]] = i;
        } else {
            hash[words[i]]++;
        }
    }

    int wsize = words[0].size();
    for (int start = 0; start < wsize; start++) {
        int count = 0;
        unordered_map<string, int> slidingWindow;
        for (int i = start; i + wsize <= s.length(); i += wsize) {
            string word = s.substr(i, wsize);
            //cout << "yes" << endl;
            if (hash.find(word) == hash.end()) {
                //cout << "yes" << endl;
                slidingWindow.clear();
                count = 0;
            } else {
                count++;
                if (slidingWindow.find(word) == slidingWindow.end()) {
                    slidingWindow[word] = 1;
                } else {
                    slidingWindow[word]++;
                }
                while (hash[word] < slidingWindow[word]) {
                    string removedWord = s.substr(i - (count-1) * wsize, wsize);
                    slidingWindow[removedWord]--;
                    count--;
                }
            }

            if (count == words.size()) {
                res.push_back(i - (count - 1) * wsize);
            }
        }
    }
    return res;
}
string countAndSay(int n) {
    if (0 == n) return "";
    if (1 == n) return "1";
    string res="1";
    string s;
    for (int i = 1; i < n; i++) {
        int len = res.size();
        for (int j = 0; j < len; j++){

            int count=1;
            while ((j + 1 < len) && (res[j] == res[j + 1])){
                count++;
                j++;
            }
           // s += std::to_string(count) + res[j];
        }
        res = s;
        s.clear();
    }

    return res;
}
int main() {
    int* pint = 0;
    pint += 6;
    cout << pint << endl;

    string str = "barfoothefoobarman";
    vector<string> words{"foo", "bar"};
    for (auto c: words)
        cout << c << endl;
    vector<int> res = findSubstring(str, words);
    for (auto c : res)
        cout << c ;
    cout << endl;
    string str1;
    auto size = strlen("ABCD");
    return 0;
}
