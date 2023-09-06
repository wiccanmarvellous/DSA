#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// old
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode*tail) {
        if (head->next == tail)
            return head;
        ListNode *prev = nullptr, *curr = head, *next = head->next;
        while (next != tail) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr && head->next == nullptr)
            return head;
        ListNode *prev = nullptr, *start = head, *tail = head;
        int i = 1, flag = 1;
        while (i++ < k)
            tail = tail->next;
        ListNode *tail_next = tail->next;
        while (tail != nullptr) {
            if (flag) {
                head = tail;
                flag = 0;
            }
            ListNode *temp = start;
            start = reverseList(start, tail->next);
            tail = temp;
            if (prev)
                prev->next = start;
            tail->next = tail_next;
            prev = tail;
            i = 1;
            while (i++ <= k && tail != nullptr) {
                start = start->next;
                tail = tail->next;
            }
            if (tail != nullptr)
                tail_next = tail->next;
        }
        prev->next = tail_next;
        return head;
    }
};

// new
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prevSub = dummy, *curr = head;
        int flag = 0;
        while (curr != NULL) {
            ListNode *subHead = curr, *prev = NULL;
            for (int i = 0; i < k; i++) {
                if (curr == NULL) {
                    curr = prev;
                    prev = NULL;
                    while (curr != NULL) {
                        ListNode *nxt = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = nxt;
                    }
                    prevSub->next = prev;
                    return head;
                }
                ListNode *nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            if  (flag == 0) {
                head = prev;
                flag++;
            }
            prevSub->next = prev;
            subHead->next = curr;
            prevSub = subHead;
        }
        return head;
    }
};