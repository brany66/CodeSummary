//
// Created by BranY on 2016/8/9.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/word-search/
// https://leetcode.com/problems/word-search-ii/

#include <iostream>
#include <vector>
using namespace std;
/* Solution 79 */
bool dfs(int row, int col, string word, int index, vector<vector<char>> board) {
    if(index == word.length() - 1) return true;
    char map = board[row][col];
    board[row][col] = '#';
    //
    if(row - 1 >= 0 && board[row - 1][col] == word[index + 1]) {
        if(dfs(row - 1, col, word, index + 1, board))
            return true;
    }
    //down
    if(row + 1 < board.size() && board[row+1][col] == word[index + 1]) {
        if(dfs(row + 1, col,word, index + 1, board))
            return true;
    }
    //left
    if(col - 1 >=0 && board[row][col - 1] == word[index + 1]) {
        if(dfs(row, col - 1, word, index + 1, board))
            return true;
    }
    //right
    if(col + 1 < board[0].size() && board[row][col + 1] == word[index + 1]) {
        if(dfs(row, col + 1, word, index + 1, board))
            return true;
    }

    board[row][col] = map;
    return false;
}
bool exist(vector<vector<char>> &board, string word) {
    if(word.length() == 0)
        return true;
    if(board.size() == 0 || board[0].size() == 0)
        return false;
    for(int i = 0;i < board.size() ;i++) {
        for(int j = 0;j < board[0].size();j++) {
            if(board[i][j] == word[0] && dfs(i, j, word, 0, board))
                return true;
        }
    }
    return false;
}
/* Solution 212 */
/**
 * "a", {"a","a"}
 * TLE
 */
vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    vector<string> res;
    if (board.size() == 0 || board[0].size() == 0 || words.size() == 0) return res;
    int k = 0;
    while (k < words.size()) {
        for(int i = 0;i < board.size() ;i++) {
            for(int j = 0;j < board[0].size();j++) {
                if(board[i][j] == words[k][0] && dfs(i, j, words[k], 0, board)) {
                    bool flag = false;
                    vector<string>::iterator it = res.begin();
                    while (it != res.end()) {
                        if (*it == words[k]) {
                            flag = true;
                            break;
                        }
                        it++;
                    }
                    if (!flag) res.push_back(words[k]);
                }
            }
        }
        k++;
    }
    return res;
}
/**
 * Trie + BP
 * Solution 212
 *
 * */
class Trie{
public:
    Trie *children[26]; // pointers to its substrings starting with 'a' to 'z'
    bool leaf; // if the node is a leaf, or if there is a word stopping at here
    int idx; // if it is a leaf, the string index of the array words
    Trie() {
        this->leaf = false;
        this->idx = 0;
        fill_n(this->children, 26, nullptr);
    }
};

void insertWords(Trie *root, vector<string>& words, int idx) {
    int pos = 0, len = words[idx].size();
    while(pos < len) {
        if(nullptr == root->children[words[idx][pos] - 'a'])
            root->children[words[idx][pos] - 'a'] = new Trie();
        root = root->children[words[idx][pos++] - 'a'];
    }
    root->leaf = true;
    root->idx = idx;
}

Trie *buildTrie(vector<string>& words) {
    Trie *root = new Trie();
    int i;
    for(i=0; i<words.size();i++)
        insertWords(root, words, i);
    return root;
}

void checkWords(vector<vector<char>>& board, int i, int j, int row, int col, Trie *root, vector<string> &res, vector<string>& words) {
    char temp;
    if(board[i][j]=='X') return; // visited before;
    if(nullptr == root->children[board[i][j]-'a']) return ; // no string with such prefix
    else {
        temp = board[i][j];
        if(root->children[temp-'a']->leaf)  // if it is a leaf{
            res.push_back(words[root->children[temp-'a']->idx]);
            root->children[temp-'a']->leaf = false; // set to false to indicate that we found it already
        }
        board[i][j]='X'; //mark the current position as visited
// check all the possible neighbors
        if(i>0) checkWords(board, i-1, j, row, col, root->children[temp-'a'], res, words);
        if((i+1)<row) checkWords(board, i+1, j, row, col,  root->children[temp-'a'], res, words);
        if(j>0) checkWords(board, i, j-1,  row, col, root->children[temp-'a'], res, words);
        if((j+1)<col)  checkWords(board, i, j+1,  row, col, root->children[temp-'a'], res, words);
        board[i][j] = temp; // recover the current position
}

vector<string> findWords_2(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    int row = board.size();
    if(0 == row) return res;
    int col = board[0].size();
    if(0 == col) return res;
    int wordCount = words.size();
    if(0 == wordCount) return res;

    Trie *root = buildTrie(words);

    int i,j;
    for(i = 0 ; i < row; i++) {
        for(j = 0; j < col && wordCount > res.size(); j++) {
            checkWords(board, i, j, row, col, root, res, words);
        }
    }
    return res;
}
int main() {
    vector<vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    vector<string> test = {"ABCCED", "SEE", "ABCB"};
    for(auto c: test) {
        if (exist(board, c))
            cout << "true\n";
        else
            cout << "false\n";
    }
    cout << "*************************************\n";
    vector<vector<char>> board1 = {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> list = findWords_2(board1, words);
    for (auto s : list)
        cout << s << endl;
    return 0;
}


