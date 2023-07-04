#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        Node *temp = head->next, *prev_temp = head;
        while (temp) {
            if (temp->data != prev_temp->data) {
                prev_temp->next = temp;
                temp->prev = prev_temp;
                prev_temp = temp;
            }
            temp = temp->next;
        }
        prev_temp->next = nullptr;
        return head;
    }
};