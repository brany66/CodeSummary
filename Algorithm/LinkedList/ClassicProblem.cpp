//
// Created by BranY on 2016/7/24.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>
using namespace std;
/**
 * 1. 创建链表->头插法
 * 2. 创建链表->尾插法
 * 3. 正向打印链表
 * 4. 反向打印链表
 * 5. 单链表反转
 * 6. 查找单链表中的倒数第k个节点, k > 0
 * 7. 查找单链表的中间节点
 * 8. 合并两个有序链表
 * 9. 判断单链表中是否存在环
 * 10. 已知单链表中存在环，求进入环的第一个节点
 * 11. 求两个单链表相交的第一个节点
 * 12. 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted
 */
struct ListNode {
    int val;
    struct ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//1. 创建链表->头插法
ListNode* createLinkedListHead(int *arr, int N) {
    ListNode *root, *p;
    int i;
    root = new ListNode(-1);
    // root = (ListNode *)malloc(sizeof(ListNode));
    // root->next = NULL;
    for (i = 0; i < N; i++) {
        //p = (ListNode *)malloc(sizeof(ListNode));
       // p->val = arr[i];
        p = new ListNode(arr[i]);
        p->next = root->next;
        root->next = p;
    }
    return root;
}
//2. 创建链表->尾插法
ListNode* createLinkedListTail(const int* arr, int N) {
    ListNode *root, *r;
    int i;
    root = new ListNode(-1);
    //root = (ListNode *)malloc(sizeof(ListNode));
    r = root;
    for (i = 0; i < N; i++) {
        //ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        //p->val = arr[i];
        ListNode *p = new ListNode(arr[i]);
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return root;
}

//3. 正向打印链表
void printLinkedList(ListNode* head) {
    stringstream ss;
    ListNode *p = head->next;
    while (p != NULL) {
        ss << p->val << "->";
        p = p->next;
    }
    string str = ss.str();
    int index = str.find_last_of("-");

    cout << str.substr(0, index) << endl;
}
//4. 反向打印链表
void printLinkedListReverse(ListNode* head) {
    stack<ListNode *> res;
    ListNode *p = head->next;
    while (p != NULL) {
        res.push(p);
        p = p->next;
    }
    stringstream ss;
    while (!res.empty()) {
        p = res.top();
        ss << p->val << "->";
        res.pop();
    }
    string str = ss.str();
    int index = str.find_last_of("-");
    cout << str.substr(0, index) << endl;
}
//5. 单链表反转->尾插法
ListNode* reverse(ListNode* head) {
    if (head->next == NULL) return head;

//    ListNode *rev = (ListNode *)malloc(sizeof(ListNode));
//    rev->next = NULL;
    ListNode *rev = new ListNode(-1);
    ListNode *cur = head->next;
    while(cur != NULL) {
        ListNode *tmp = cur;
        cur = cur->next;
        tmp->next = rev->next;
        rev->next = tmp;
    }
    return rev;
}
//6. 查找单链表中的倒数第k个节点, k > 0
ListNode* getKthNode(ListNode* head, int k) {
    if (k == 0 || head == NULL) return NULL;
    ListNode *p = head->next;
    ListNode *prev = head->next;
    while (k > 0 && p != NULL) {
        p = p->next;
        --k;
    }
    //cout << prev->val << " " << p->val << endl;
    if (k > 1 || p == NULL) return NULL;
    while (p != NULL) {
        prev = prev->next;
        p = p->next;
    }
    return prev;
}
//7. 查找单链表的中间节点
ListNode* getMidNode(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *p = head;
    ListNode *prev = head;
    while (p->next != NULL) {
        p = p->next;
        prev = prev->next;
        if (p->next != NULL)
            p = p->next;
    }
    return prev;
}
//8. 合并两个有序链表
//   尾插法
ListNode* mergeSortedLinkedList(ListNode* A, ListNode* B) {
    if (A == NULL || A->next == NULL) return B;
    if (B == NULL || B->next == NULL) return A;
    ListNode *merge = (ListNode *)malloc(sizeof(ListNode));
    ListNode *r = merge;
    ListNode *p1 = A->next, *p2 = B->next;

    ListNode* tmp = merge;
    while (p1 != NULL && p2 != NULL) {
        ListNode *q;
        if (p1->val < p2->val) {
            q = p2;
            tmp->next = q;
            tmp = q;
            p2 = p2->next;

        } else {
            q = p1;
            tmp->next = q;
            tmp = q;
            p1 = p1->next;
        }
    }
    if(p1 != NULL)
        tmp->next = p1;
    else if(p2 != NULL)
        tmp->next = p2;
    else
        tmp->next = NULL;
    return merge;
}
// 9. 判断单链表中是否存在环
bool hasCircle(ListNode* head) {
    ListNode  *pFast, *pSlow;
    pFast = pSlow= head->next;
    while (pFast != NULL && pFast->next != NULL) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
        if (pFast == pSlow)
            return true;
    }
    return false;
}
/**
* 12. 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted
 * */
void deleteNode(ListNode* head, ListNode* toBeDeleted) {
    if (toBeDeleted == NULL)
        return;
    if (toBeDeleted->next != NULL) {
        toBeDeleted->val = toBeDeleted->next->val;
        ListNode *tmp = toBeDeleted->next;
        toBeDeleted->next = toBeDeleted->next->next;
        delete tmp;
    } else {
        //last
        if(head == toBeDeleted) // 链表中只有一个节点的情况
        {
            head = NULL;
            delete toBeDeleted;
        }
        else
        {
            ListNode * pNode = head;
            while(pNode->next != toBeDeleted) // 找到倒数第二个节点
                pNode = pNode->next;
            pNode->next = NULL;
            delete toBeDeleted;
        }
    }
}
TreeNode* convertSortListToBST(ListNode* &head, int size) {
    if (size == 0) return NULL;
    TreeNode *root = new TreeNode(0);
    root->left = convertSortListToBST(head, size/2);
    root->val = head->val;
    head = head->next;
    root->right = convertSortListToBST(head, size - size/2 - 1);
    return root;
}
TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    int size = 0;
    ListNode *p = head;
    ListNode *q = head;
    while(p != NULL) {
        size++;
        p = p->next;
    }

    return convertSortListToBST(q, size);
}

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    ListNode *head1 = createLinkedListHead(arr, N);

    printLinkedList(head1);
    //ListNode *rev = reverse(head1);
    //printLinkedList(rev);
    cout << getKthNode(head1, 3)->val << endl;
    //printLinkedListReverse(head1);
    //cout << "Reverse.\n" ;
    //ListNode* A = reverse(head1);
    //printLinkedList(A);

    //ListNode *head2 = createLinkedListTail(arr, N);
    // cout << "Tail Insert.\n" ;
    // printLinkedList(head2);
    // printLinkedListReverse(head2);

//    cout << "Reverse Kth Node " << getKthNode(head1, 2)->val << endl;
//    cout << "Middle Node " << getMidNode(head1)->val << endl;
    int M;
    cin >> M;
    int *arr2 = new int[M];
    for (int i = 0; i < M; i++)
        cin >> arr2[i];
    ListNode *head3 = createLinkedListHead(arr2, M);
   printLinkedList(head3);

    printLinkedList(mergeSortedLinkedList(head1, head3));
    return 0;
}
/**
 * 10
 * 0 1 2 3 4 5 6 7 8 9
*/