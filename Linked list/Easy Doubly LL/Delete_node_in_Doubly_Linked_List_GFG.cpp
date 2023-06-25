#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
        Node *temp = head_ref;
        if (x == 1) {
            head_ref = head_ref->next;
            delete temp;
            temp = nullptr;
            return head_ref;
        }
        int i = 1;
        while (i != x) {
            i++;
            temp = temp->next;
        }
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        temp = nullptr;
        return head_ref;
    }
};