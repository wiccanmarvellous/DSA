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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL, *curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
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
        return reverse(ansHead);
    }
};