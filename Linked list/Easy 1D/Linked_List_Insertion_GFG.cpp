#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
        Node *newnode = new Node(x);
        newnode->next = head;
        head = newnode;
        return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
        Node *newnode = new Node(x);
        if (head == NULL)
            return newnode;
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        return head;
    }
};