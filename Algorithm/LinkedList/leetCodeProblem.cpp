//
// Created by BranY on 2016/7/26.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>

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
/**
 * https://leetcode.com/problems/merge-k-sorted-lists/
 * @param lists Array of Sorted LinkedList
 * @return merged List
 */
ListNode* MERGE(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    ListNode *res, *p;
    res = p = (l1->val < l2->val) ? l1 : l2;
    ListNode *q = (l1->val < l2->val) ? l2 : l1;
    while (p != NULL && q != NULL) {
        while (p->next != NULL && p->next->val <= q->next->val)
            p = p->next;
        ListNode *old = p->next;
        p->next = q;
        p = q;
        q = old;
    }
    return res;
}
ListNode* helper(vector<ListNode*>& lists, int l, int r) {
    if (l < r) {
        int m = (l+r) / 2;
        return MERGE(helper(lists, l, m), helper(lists, m+1, r));
    }
    return lists[l];
}
ListNode * mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return NULL;
    if (lists.size() == 1) return lists[0];
    return helper(lists, 0, lists.size() - 1);
}

/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 * @return
 */
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k <= 1)
        return head;
    int len = 0;
    ListNode *p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    if (k > len)
        return head;
    ListNode *q = head;
    p = NULL;
    int n = k;
    while (q != NULL && n > 0)
    {
        ListNode *x = q->next;
        q->next = p;
        p = q;
        q = x;
        n--;
    }
    head->next = q;
    if (len - k >= k)
        head->next = reverseKGroup(q, k);
    else
        head->next = q;
    return p;
}
/**
 * https://leetcode.com/problems/odd-even-linked-list/
 * @return
 */
ListNode* oddEvenList(ListNode* head) {
    queue<ListNode*> ST;
    if (head == NULL) return head;
    ListNode fake(-1);
    fake.next = head;
    ListNode *prev = &fake;
    ListNode *p = prev->next;
    int i = 0;
    while (p != NULL) {
        if (i % 2 != 0) {
            ListNode *tmp = p;
            ST.push(tmp);
            prev->next = tmp->next;
            p = prev->next;
        } else {
            prev = p;
            p = p->next;
        }
        ++i;
    }
    while(!ST.empty()) {
        ListNode *tmp = ST.front();
        tmp->next = NULL;
        prev->next = tmp;
        prev = tmp;
        ST.pop();
    }
    return fake.next;
}
/**
 * 查找单链表的中间节点
 * @param head
 * @return
 */
ListNode* getMidNode(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode fake(-1);
    fake.next = head;
    ListNode *p = &fake;
    ListNode *prev = &fake;
    while (p->next != NULL) {
        p = p->next;
        prev = prev->next;
        if (p->next != NULL)
            p = p->next;
    }
    //cout << prev->val << endl;
    return prev;
}
ListNode *reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode fake(-1);
    //fake.next = head;
    ListNode *cur = head;
    while (cur != NULL) {
        ListNode *tmp = cur;
        cur = cur->next;
        tmp->next = fake.next;
        fake.next = tmp;
    }
    return fake.next;
}
bool isPalindrome(ListNode* head) {
    if (head == NULL|| head->next == NULL) return true;
    ListNode *p = head;
    ListNode *mid = reverse(getMidNode(p)->next);
    p = head;
    while (p != NULL && mid != NULL) {
        if (p->val != mid->val)
            return false;
        p = p->next;
        mid = mid->next;
    }
    return true;
}
/**
 * https://leetcode.com/problems/insertion-sort-list/
 * @param head
 * @return
 */
ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode fake(-1);
    ListNode *prev = &fake;
    ListNode *cur = head;
    while (cur != NULL) {
        ListNode *next = cur->next;
        prev = &fake;
        while (prev->next != NULL && prev->next->val <= cur->val)
            prev = prev->next;
        cur->next = prev->next;
        prev->next = cur;
        cur = next;
    }
    return fake.next;
}
int main()
{
    int N1;
    cin >> N1;
    int *arr1 = new int[N1];
    for (int i = 0; i < N1; i++)
        cin >> arr1[i];
    ListNode *h1 = createLinkedListTail(arr1, N1);
    printLinkedList(h1);

    printLinkedList(insertionSortList(h1));

//    cout << getMidNode(h1)->val << endl;
//
//    if (isPalindrome(h1))
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
    //printLinkedList(oddEvenList(h1));
//    int K;
//    cin >> K;
//    printLinkedList(reverseKGroup(h1, K));

    //printLinkedList(addTwoNumbers(h1, h2));

    //printLinkedList(removeNthFromEnd(h1, 3));
    //printLinkedList(removeNthFromEnd(h2, 6));
    return 0;
}
