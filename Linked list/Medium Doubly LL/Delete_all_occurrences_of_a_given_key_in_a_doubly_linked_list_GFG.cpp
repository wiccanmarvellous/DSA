#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        while (*head_ref && (*head_ref)->data == x)
            *head_ref = (*head_ref)->next;
        
        Node *temp = *head_ref;
        while (temp) {
            if (temp->data == x) {
                temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
            }
            temp = temp->next;
        }
    }
};