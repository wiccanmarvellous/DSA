#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(nullptr) {}
};

// Iterative Approaches

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *t1 = head, *t2 = head->next, *t3 = head->next->next;
        t1->next = nullptr;        
        while (t3 != nullptr) {
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t3->next;
        }
        t2->next = t1;
        head = t2;
        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *t1 = head, *t2 = head->next;
        t1->next = nullptr;        
        while (t2 != nullptr) {
            ListNode *t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;
        }
        head = t1;
        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = nullptr;
        while (head != nullptr) {
            ListNode *next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL) {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};

// Rcursive Approaches

class Solution {
public:
    ListNode* recursive(ListNode* next_node, ListNode* curr_node, ListNode* prev_node) {
        if (next_node == nullptr) {
            curr_node->next = prev_node;
            return curr_node;
        }
        curr_node->next = prev_node;
        return recursive(next_node->next, next_node, curr_node);
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        return recursive(head->next, head, nullptr);
    }
};

class Solution {
public:
    ListNode* recursive(ListNode* curr_node, ListNode* prev_node) {
        if (curr_node == nullptr)
            return prev_node;
        ListNode *next_node = curr_node->next;
        curr_node->next = prev_node;
        return recursive(next_node, curr_node);
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        return recursive(head, nullptr);
    }
};

class Solution {
public:
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev) {
        if (curr == NULL) {
            head = prev;
            return;
        }
        reverse(head, curr->next, curr);
        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        reverse(head, head, NULL);
        return head;
    }
};