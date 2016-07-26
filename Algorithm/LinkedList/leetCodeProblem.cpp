//
// Created by BranY on 2016/7/26.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};
//1. 创建链表->头插法
ListNode* createLinkedListHead(int *arr, int N) {
    ListNode *root, *p;
    int i;
    root = new ListNode(-1);
    root->next = NULL;
    for (i = 0; i < N; i++) {
        p = new ListNode(arr[i]);
        p->next = root->next;
        root->next = p;
    }
    return root->next;
}
//2. 创建链表->尾插法
ListNode* createLinkedListTail(const int* arr, int N) {
    ListNode *root, *r;
    int i;
    root = new ListNode(-1);
    r = root;
    for (i = 0; i < N; i++) {

        ListNode *p = new ListNode(arr[i]);
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return root->next;
}
void printLinkedList(ListNode *head) {
    stringstream ss;
    ListNode *p = head;
    while (p != NULL) {
        ss << p->val << "->";
        p = p->next;
    }
    string str = ss.str();
    int index = str.find_last_of("-");

    cout << str.substr(0, index) << endl;
}
void printLinkedList(ListNode *head);
/**
 * Add Two Numbers
 * Link: https://leetcode.com/problems/add-two-numbers/
 * @return result Linked List
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode fake(-1);
    ListNode *p = &fake;
    int cin = 0;
    while (l1 != NULL && l2 != NULL) {
        int val = cin + (l1 ? l1->val : 0) + (l2 ? l2->val :  0);
        cin = val / 10;
        p->next = new ListNode(val % 10);
        p = p->next;
        if (l1)
            l1 = l1->next;
        if(l2)
            l2 =l2->next;
    }
    if (cin != 0) {
        p->next = new ListNode(cin);
        p = p->next;
    }
    return fake.next;
}
/**
 * Remove Nth Node From End Of List
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * @return result list
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n <= 0 || head == NULL) return head;
    int i = 0, j = 0;
    ListNode *p = head, *prev = NULL;
    ListNode *tmp = head;
    while (p != NULL) {
        ++j;
        if ((j-i) == n && p->next != NULL) {
            ++i;
            prev = tmp;
            tmp = tmp->next;
        } else if ((j-i) == n && p->next == NULL) {
            if (i == 0)
                head = head->next;
            else
                prev->next = tmp->next;
        }
        p = p->next;
    }
    return head;
}
int main()
{
    int N1, N2;
    cin >> N1 >> N2;
    int *arr1 = new int[N1];
    for (int i = 0; i < N1; i++)
        cin >> arr1[i];
    ListNode *h1 = createLinkedListTail(arr1, N1);
    printLinkedList(h1);

    int *arr2 = new int[N2];
    for (int i = 0; i < N2; i++)
        cin >> arr2[i];
    ListNode *h2 = createLinkedListTail(arr2, N2);
    printLinkedList(h2);

    //printLinkedList(addTwoNumbers(h1, h2));

    printLinkedList(removeNthFromEnd(h1, 3));
    printLinkedList(removeNthFromEnd(h2, 6));
    return 0;
}
