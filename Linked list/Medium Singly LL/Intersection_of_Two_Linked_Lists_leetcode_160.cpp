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

// Optimal 1      TC O(m + n)     SC O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        while (tempA != nullptr && tempB != nullptr) {
            tempB = tempB->next;
            tempA = tempA->next;
        }
        int len = 0;
        if (tempA == nullptr) {
            while (tempB != nullptr) {
                len++;
                tempB = tempB->next;
            }
            tempA = headA;
            tempB = headB;
            while (len--)
                tempB = tempB->next;
        }
        else {
            while (tempA != nullptr) {
                len++;
                tempA = tempA->next;
            }
            tempA = headA;
            tempB = headB;
            while (len--)
                tempA = tempA->next;
        }
        while (tempA != nullptr) {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};

// Optimal 2      TC O(m + n)     SC O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        while (tempA != nullptr && tempB != nullptr) {
            tempB = tempB->next;
            tempA = tempA->next;
        }
        if (tempA == nullptr) {
            tempA = headB;
            while (tempB != nullptr) {
                tempA = tempA->next;
                tempB = tempB->next;
            }
            tempB = headA;
        }
        else {
            tempB = headA;
            while (tempA != nullptr) {
                tempA = tempA->next;
                tempB = tempB->next;
            }
            tempA = headB;
        }
        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};