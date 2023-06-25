#include <bits/stdc++.h>
using namespace std;



struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

void addNode(Node *head, int pos, int data)
{
    Node *temp = head, *newnode = new Node(data);
    int i = 0;
    while (i != pos) {
        i++;
        temp = temp->next;
    }
    if (temp->next == NULL)
        newnode->next = NULL;
    else {
        temp->next->prev = newnode;
        newnode->next = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
}