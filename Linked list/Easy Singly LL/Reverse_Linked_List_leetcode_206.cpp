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