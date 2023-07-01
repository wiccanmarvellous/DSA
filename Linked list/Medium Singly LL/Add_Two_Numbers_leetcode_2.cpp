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
        int sum = 0, cy = 0;
        ListNode *t1 = l1, *t2 = l2, *l3 = nullptr, *t3 = nullptr;
        while (t1 != nullptr || t2 != nullptr) {
            if (t1 == nullptr) {
                sum = t2->val + cy;
                t2 = t2->next;
            }
            else if (t2 == nullptr) {
                sum = t1->val + cy;
                t1 = t1->next;
            }
            else {
                sum = t1->val + t2->val + cy;
                t1 = t1->next;
                t2 = t2->next;
            }
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