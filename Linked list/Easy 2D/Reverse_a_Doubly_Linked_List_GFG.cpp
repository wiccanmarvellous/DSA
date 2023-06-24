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

Node* reverseDLL(Node * head)
{
    if (head->next == nullptr)
        return head;
    Node *t1 = head;
    Node *t2 = t1->next;
    Node *t3 = t2->next;
    t1->next = nullptr;
    t1->prev = t2;
    while (t3 != nullptr) {
        t2->next = t1;
        t2->prev = t3;
        t1 = t2;
        t2 = t3;
        t3 = t3->next;
    }
    t2->next = t1;
    t2->prev = nullptr;
    head = t2;
    return head;
}