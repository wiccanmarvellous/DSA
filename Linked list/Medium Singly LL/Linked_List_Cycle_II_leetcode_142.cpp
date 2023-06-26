#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute    TC O(n)     SC O(n)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> set;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            if (set.find(temp) != set.end())
                return temp;
            set.insert(temp);
            temp = temp->next;
        }
        return nullptr;
    }
};

// Optimal      TC O(n)     SC O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};