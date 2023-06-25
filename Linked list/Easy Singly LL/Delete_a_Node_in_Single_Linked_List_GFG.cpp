#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* deleteNode(Node *head,int x)
{
    if (x == 1)
        return head->next;
    Node *temp = head;
    int i = 1;
    while (i + 1 != x) {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
    return head;
}