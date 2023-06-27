#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute        TC O(n)     SC O(n / 2)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode *temp = head;
        int len = 0, i = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        temp = head;
        while (i < len / 2) {
            stack.push(temp->val);
            temp = temp->next;
            i++;
        }
        if ((len & 1) == 1) {
            temp = temp->next;
            i++;
        }
        while (i < len) {
            if (stack.top() != temp->val)
                return false;
            stack.pop();
            temp = temp->next;
            i++;
        }
        return true;
    }
};

// Optimal      TC O(n)     SC O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = nullptr;
        while (head != nullptr) {
            ListNode *next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head, *slow = head, *fast = head;
        int len = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (len % 2 != 0)
            slow = slow->next;
        slow = reverseList(slow);
        temp = head;
        while (slow != nullptr) {
            if (temp->val != slow->val)
                return false;
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};