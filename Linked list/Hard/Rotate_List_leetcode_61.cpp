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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        int len = 1;
        ListNode *temp = head;
        while (temp->next) {
            temp = temp->next;
            len++;
        }
        k %= len;
        while (k--) {
            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }
        return head;
    }
};