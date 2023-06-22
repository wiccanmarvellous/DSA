#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
  public:
    bool searchKey(int n, struct Node* head, int key) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

class Solution {
  public:
    bool searchKey(int n, struct Node* head, int key) {
        if (head == NULL)
            return false;
        else if (head->data == key)
            return true;
        return searchKey(n, head->next, key);
    }
};