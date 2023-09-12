#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, cy = 0, val1, val2;
        ListNode *t1 = l1, *t2 = l2, *l3 = nullptr, *t3 = nullptr;
        while (t1 != nullptr || t2 != nullptr) {
            if (t1) val1 = t1->val, t1 = t1->next;
            else val1 = 0;
            if (t2) val2 = t2->val, t2 = t2->next;
            else val2 = 0;
            sum = val1 + val2 + cy;
            ListNode *newnode = new ListNode(sum % 10);
            cy = sum / 10;
            if (l3 == nullptr)
                l3 = newnode;
            else
                t3->next = newnode;
            t3 = newnode;
        }
        if (cy) {
            ListNode *newnode = new ListNode(cy);
            t3->next = newnode;
        }
        return l3;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        int carry = 0, val1 = 0, val2 = 0, sum = 0;
        while (l1 || l2 || carry) {
            if (l1) 
                val1 = l1->val; 
            else 
                val1 = 0;
            if (l2) 
                val2 = l2->val; 
            else 
                val2 = 0;

            sum = val1 + val2 + carry;
            carry = sum / 10;
            ListNode *newnode = new ListNode(sum % 10);
            curr->next = newnode;
            curr = newnode;

            if (l1) 
                l1 = l1->next; 
            if (l2) 
                l2 = l2->next; 
        }
        return dummy->next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *curr1 = l1, *curr2 = l2, *ansHead = NULL, *ansCurr = NULL;
        int carry = 0, sum = 0;
        while (curr1 != NULL && curr2 != NULL) {
            sum = curr1->val + curr2->val + carry;
            carry = sum / 10;
            ListNode *newnode = new ListNode(sum % 10);
            if (ansHead == NULL)
                ansHead = newnode;
            else
                ansCurr->next = newnode;
            ansCurr = newnode;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while (curr1) {
            sum = curr1->val + carry;
            carry = sum / 10;
            ListNode *newnode = new ListNode(sum % 10);
            ansCurr->next = newnode;
            ansCurr = newnode;
            curr1 = curr1->next;
        }
        while (curr2) {
            sum = curr2->val + carry;
            carry = sum / 10;
            ListNode *newnode = new ListNode(sum % 10);
            ansCurr->next = newnode;
            ansCurr = newnode;
            curr2 = curr2->next;
        }
        
        if (carry) {
            ListNode *newnode = new ListNode(carry);
            ansCurr->next = newnode;
            ansCurr = newnode;
        }
        return ansHead;
    }
};