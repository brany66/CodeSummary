//
// Created by BranY on 2016/7/24.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#include <string>
#include <iostream>

typedef struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int val = 0, struct ListNode* next = NULL) : val(val), next(next) {}
} Node;
class List {
private:
    ListNode* head;
    int size;
public:
    List();
    List(const List&);
    List& operator = (const List&);
    ~List();

    bool empty(void)const;
    int  Size(void)const;
    std::string toString(void) const;

    void insert(int position, const int& data);
    void delateNode(int position);
    void clear(void) {
        if (this->head != NULL) {
            ListNode* p = this->head;
            while (p != NULL) {
                ListNode* temp = p;
                p = p->next;
                delete temp;
            }
            this->head = NULL;
        }
        this->size = 0;
    }
    List& sort(void);
};
#endif //ALGORITHM_LIST_H
