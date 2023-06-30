#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute        TC O(m * n)     SC O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        while (tempA != nullptr) {
            while (tempB != nullptr) {
                if (tempA == tempB)
                    return tempB;
                tempB = tempB->next;
            }
            tempA = tempA->next;
            tempB = headB;
        }
        return nullptr;
    }
};

// Better        TC O(m + n)     SC O(m)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        ListNode *temp = headA;
        while (temp != nullptr) {
            set.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (set.find(temp) != set.end())
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};