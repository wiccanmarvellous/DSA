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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int len = 0, i = 1;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        n = len - n;
        if (n == 0)
            return head->next;
        temp = head;
        while (i < n) {
            i++;
            temp = temp->next;
        }
        if (temp->next != nullptr)
            temp->next = temp->next->next;
        else
            temp->next = nullptr;
        return head;
    }
};