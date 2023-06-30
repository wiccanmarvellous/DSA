#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute        TC O(n * n)     SC O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *i = head, *j = head;
        while (i != nullptr) {
            int m = INT_MAX;
            ListNode *hold = nullptr;
            j = i;
            while (j != nullptr) {
                if (m > j->val) {
                    m = j->val;
                    hold = j;
                }
                j = j->next;
            }
            hold->val = i->val;
            i->val = m;
            i = i->next;
        }
        return head;
    }
};

// Better       TC O(n)     SC O(n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode *temp = head;
        while (temp !=  nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};