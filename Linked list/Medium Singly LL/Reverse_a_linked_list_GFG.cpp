#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};

// Iterative Approach

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        Node *t1 = head, *t2 = head->next, *t3 = head->next->next;
        t1->next = nullptr;
        while (t3 != nullptr) {
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t3->next;
        }
        t2->next = t1;
        head = t2;
        return head;
    }
    
};
    
// Recursive Approach

class Solution
{
    public:
    struct Node* recursive(Node* curr_node, Node* prev_node) {
        if (curr_node == nullptr)
            return prev_node;
        Node *next_node = curr_node->next;
        curr_node->next = prev_node;
        return recursive(next_node, curr_node);
    }
    
    struct Node* reverseList(struct Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        return recursive(head, nullptr);
    }
    
};
    