#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        if (*head_ref == nullptr)
            return;
        Node *temp = *head_ref;
        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                if (temp != *head_ref)
                    temp->prev->next = temp->next;
                else
                    *head_ref = temp->next;
                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
            }
            temp = temp->next;
        }
    }
};