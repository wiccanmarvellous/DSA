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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int len = 0, i = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        temp = head;
        while (i < len / 2) {
            i++;
            temp = temp->next;
        }
        return temp;
    }
};