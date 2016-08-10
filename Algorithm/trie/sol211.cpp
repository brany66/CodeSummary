//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/add-and-search-word-data-structure-design/

#include <iostream>
#include <vector>

using namespace std;
class TrieNode {
public:
    TrieNode *child[26];
    bool leaf;
    TrieNode () : leaf(false) {
        for (auto &a : child) a = nullptr;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->leaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool searchWord(string word, TrieNode *root, int index) {
        if (index == word.size()) return root->leaf;
        if (word[index] == '.') {
            for (auto &a : root->child) {
                if (a && searchWord(word, a, index+1)) return true;
            }
            return false;
        } else {
            return root->child[word[index] - 'a'] && searchWord(word, root->child[word[index] -'a'], index+1);
        }
    }
    bool search(string word) {
        return searchWord(word, root, 0);
    }

private:
    TrieNode *root;
};
int main() {
    return 0;
}

