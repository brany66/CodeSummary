//
// Created by BranY on 2016/8/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
// https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <unordered_map>

using namespace std;
struct Node {
    int key;
    int val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};
Node *head, *tail;
unordered_map<int, Node*> map;
int curcap; // current size
int maxcap; // max size
void deleteNode(Node * node) {
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
}
void addToHead(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}
void init(int capacity) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
    curcap = 0;
    maxcap = capacity;
}
int get(int key) {
    if (!map[key]) return -1;
    else {
        Node *node = map[key];
        deleteNode(node);
        addToHead(node);
        return node->val;
    }
}
void set(int key, int val) {
    if (!map[key]) {
        if (curcap == maxcap) {
            map[tail->prev->key] = NULL;
            deleteNode(tail->prev);
        }
        Node *node = new Node(key, val);
        addToHead(node);
        map[key] = node;
        if (curcap < maxcap) ++curcap;
    } else {
        Node *node = map[key];
        node->val = val;
        deleteNode(node);
        addToHead(node);
    }
}
int main() {
    return 0;
}
