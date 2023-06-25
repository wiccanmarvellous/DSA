#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node *head = NULL, *temp = NULL;
        for (auto i : arr) {
            Node *newnode = new Node(i);
            if (head == NULL)
                head = temp = newnode;
            else {
                temp->next = newnode;
                newnode->prev = temp;
                temp = newnode;
            }
        }
        return head;
    }
};