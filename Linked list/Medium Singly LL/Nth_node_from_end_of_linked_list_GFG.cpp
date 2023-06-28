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

class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
        Node *i = head, *j = head;
        int m = 0;
        while (j != nullptr && m < n) {
            m++;
            j = j->next;
        }
        if (j == nullptr) {
            if (m == n)
                return head->data;
            return -1;
        }
        while (j->next != nullptr) {
            i = i->next;
            j = j->next;
        }
        return i->next->data;
    }
};
