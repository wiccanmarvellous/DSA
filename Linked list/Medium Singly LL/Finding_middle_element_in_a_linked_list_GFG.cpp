#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

class Solution{
    public:
    int getMiddle(Node *head)
    {
        if (head == nullptr)
            return -1;
        Node *temp = head;
        int len = 0, i = 0;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        temp = head;
        while (i < len / 2)
        {
            i++;
            temp = temp->next;
        }
        return temp->data;
    }
};

class Solution{
    public:
    int getMiddle(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};