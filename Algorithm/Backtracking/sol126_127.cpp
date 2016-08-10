//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/word-ladder/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
/**
 * Solution 127
 */
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    unordered_set<string> head({beginWord}), tail({endWord});

    int minPath = 2, headLen = 1, tailLen = 1;
    while (headLen && tailLen) {
        if (headLen > tailLen) {
            swap(head, tail);
            swap(headLen, tailLen);
        }
        unordered_set<string> tmp;
        for (auto it = head.begin(); it != tmp.end(); it++) {
            string str(*it);
            for (int i = 0; i < str.size(); i++) {
                char t = str[i];
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    if(ch == str[i]) continue;
                    str[i] = ch;
                    if(tail.find(str) != tail.end())
                        return minPath;
                    if(wordList.find(str) != wordList.end()) {
                        tmp.insert(str);
                        wordList.erase(str);
                    }
                }
                str[i] = t;
            }
        }
        swap(head, tmp);
        headLen = head.size();
        ++minPath;
    }
    return minPath;
}
void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
    wordDict.erase(word);
    for (int p = 0; p < word.size(); p++) {
        char letter = word[p];
        for (int k = 0; k < 26; k++) {
            char c = 'a';
            c += k;
            word[p] = c;
            if (wordDict.find(word) != wordDict.end()) {
                toVisit.push(word);
                wordDict.erase(word);
            }
        }
        word[p] = letter;
    }
}
int ladderLength_2(string beginWord, string endWord, unordered_set<string>& wordDict) {
    if (wordDict.size() == 2 && (wordDict.find(beginWord) != wordDict.end() && wordDict.find(endWord) != wordDict.end())) return 0;
    wordDict.insert(endWord);
    queue<string> toVisit;
    addNextWords(beginWord, wordDict, toVisit);
    int dist = 2;
    while (!toVisit.empty()) {
        int num = toVisit.size();
        for (int i = 0; i < num; i++) {
            string word = toVisit.front();
            toVisit.pop();
            if (word == endWord) return dist;
            addNextWords(word, wordDict, toVisit);
        }
        dist++;
    }
    return (dist != 2) ? dist : 0;
}
/**
 * Solution 126
 */
//从前驱路径中回溯构造path
void ConstructResult(unordered_map<string,vector<string> > &prePath,
                     vector<vector<string> > &res, vector<string> &tmp,
                     string &start, string &end)
{
    if(start == end) {
        reverse(tmp.begin(), tmp.end());
        res.push_back(tmp);
        reverse(tmp.begin(), tmp.end());
        return;
    }
    vector<string> &pre = prePath[end];
    for(int i = 0; i < pre.size(); i++) {
        tmp.push_back(pre[i]);
        ConstructResult(prePath, res, tmp, start, pre[i]);
        tmp.pop_back();
    }

}
typedef unordered_set<string>::iterator HashIter;
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    queue<string> Q;
    Q.push(start); Q.push("");
    bool hasFound = false;
    unordered_map<string,vector<string>> prePath;//前驱路径
    unordered_set<string> hashtable;//保证bfs时插入队列的元素不存在重复
    while(Q.empty() == false) {
        string str = Q.front(), strCopy = str;
        Q.pop();
        if(str != "") {
            int strLen = str.length();
            for(int i = 0; i < strLen; i++) {
                char tmp = str[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    if(c == tmp)continue;
                    str[i] = c;
                    if(str == end) {
                        hasFound = true;
                        prePath[end].push_back(strCopy);
                        //找到了一条最短路径，当前单词的其它转换就没必要
                        goto END;
                    }
                    if(dict.find(str) != dict.end()) {
                        prePath[str].push_back(strCopy);
                        //保证bfs时插入队列的元素不存在重复
                        if(hashtable.find(str) == hashtable.end())
                        {Q.push(str); hashtable.insert(str);}
                    }
                }
                str[i] = tmp;
            }
        }
        else if(Q.empty() == false) {////到当前层的结尾，且不是最后一层的结尾
            if(hasFound)break;
            //避免进入死循环，把bfs上一层插入队列的元素从字典中删除
            for(HashIter ite = hashtable.begin(); ite != hashtable.end(); ite++)
                dict.erase(*ite);
            hashtable.clear();
            Q.push("");
        }
        END: ;
    }
    vector<vector<string> > res;
    if(prePath.find(end) == prePath.end())return res;
    vector<string> tmp;
    tmp.push_back(end);
    ConstructResult(prePath, res, tmp, start, end);
    return res;
}


int main() {
    unordered_set<string> wordDict = {"hot","dot","dog","lot","log"};
    string start = "hit";
    string end = "cog";
    cout << ladderLength(start, end, wordDict) << endl;
    //cout << ladderLength_2(start, end, wordDict)<< endl;
    return 0;
}