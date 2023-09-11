#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy, *first = head, *second = head->next;
        while (head != NULL || head->next != NULL) {
            first->next = second->next;
            prev->next = second;
            second->next = first;
            head = first->next;
            prev = first;
        }
        return dummy->next;
    }
};