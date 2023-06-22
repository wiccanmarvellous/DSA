#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution
{
    public:
    int getCount(struct Node* head){
        if (head == NULL)
            return 0;
        int count = 1;
        Node *temp = head;
        while (temp->next != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
    