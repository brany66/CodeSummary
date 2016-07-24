//
// Created by BranY on 2016/7/24.
// Contact at wyang@smail.nju.edu.cn
//

#include "list.h"
#include <sstream>

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
std::string change(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

List::List() {
    head = NULL;
    size = 0;
}
List::~List() {
    clear();
}
List& List::operator=(const List & l) {
    clear();
    if (l.head == NULL) {
        head = NULL;
        size = 0;
    } else {
        ListNode* p = l.head->next;
        size = 1;
        head = new Node(l.head->val);
        for (int i = 1; i < l.size; i++) {
            insert(i, p->val);
            p = p->next;
        }
        size = l.size;
    }
    return *this;
}

List::List(const List &other) {
    this->head = NULL;
    this->size = 0;
    *(this) = other;
}

bool List::empty() const {
    if (head != NULL) return false;
    return true;
}

std::string List::toString() const {
    std::string str= "";
    ListNode* p = head;
    while (p != NULL) {
        str += change(p->val);
        str +="->";
        p = p->next;
    }
}

int List::Size() const {
    return size;
}

void List::insert(int position, const int &data) {
    if (position > size) return;
    else {
        ListNode *cur = new Node(data);
        if (position == 0) {
            cur->next = head;
            head = cur;
            size++;
        } else {
            ListNode *ptr = head;
            while (--position)
                ptr = ptr->next;
            cur->next = ptr->next;
            ptr->next = cur;
            size++;
        }
    }
}

void List::delateNode(int position) {
    if (position < size) {
        if (position != 0) {
            ListNode *p = head;
            while (--position)
                p = p->next;
            ListNode* tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            size--;
        } else {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }
    } else
        return;
}

List& List::sort() {
    int *a = new int[size];
    ListNode *p = head;
    int i = 0;
    while (p != NULL) {
        a[i++] = p->val;
        p = p->next;
    }
    for(int p = 0; p < size - 1; p++)
        for (int q = size - 1; q > p; q--)
            if (a[q-1] > a[q]) swap(&a[q-1], &a[q]);

    p = head;
    i = 0;
    while (p != NULL) {
        p->val = a[i++];
        p = p->next;
    }
    delete []a;
    return *this;
}