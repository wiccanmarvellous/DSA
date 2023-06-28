#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute        TC O(n)     SC O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *temp = head, *odd_head = nullptr, *even_head = nullptr;
        ListNode *odd_temp = nullptr, *even_temp = nullptr;
        int i = 0;
        while (temp != nullptr) {
            ListNode *newnode = new ListNode(temp->val);
            if (i % 2 == 0) {
                if (even_head == nullptr) 
                    even_head = even_temp =  newnode;
                else {
                    even_temp->next = newnode;
                    even_temp = newnode;
                }
            }
            else {
                if (odd_head == nullptr) 
                    odd_head = odd_temp =  newnode;
                else {
                    odd_temp->next = newnode;
                    odd_temp = newnode;
                }
            }
            temp = temp->next;
            i++;
        }
        even_temp->next = odd_head;
        return even_head;
    }
};

// Optimal      TC O(n)     SC O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *i = head, *j = head->next, *iH = head, *jH = head->next;
        while (j != nullptr && j->next != nullptr) {
            i->next = i->next->next;
            j->next = j->next->next;
            i = i->next;
            j = j->next;
        }
        if (j != nullptr)
            i->next = nullptr;
        i->next = jH;
        return iH;
    }
};