#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Brute    TC O(n)     SC O(n)
class Solution {
public:
    bool hasCycle(Node *head) {
        unordered_set<Node*> set;
        Node *temp = head;
        while (temp != nullptr) {
            if (set.find(temp) != set.end())
                return true;
            set.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};

// Optimal      TC O(n)     SC O(1)
class Solution
{
public:
    bool detectLoop(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};