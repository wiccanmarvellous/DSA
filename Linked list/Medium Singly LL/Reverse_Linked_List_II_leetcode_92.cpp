#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Optimal      TC O(n)        SC O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *leftPrev = dummy, *curr = head;
        for (int i = 0; i < left - 1; i++) {
            leftPrev = leftPrev->next;
            curr = curr->next;
        }
        ListNode *prev = NULL, *subHead = curr;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        leftPrev->next = prev;
        subHead->next = curr;
        return dummy->next;
    }
};