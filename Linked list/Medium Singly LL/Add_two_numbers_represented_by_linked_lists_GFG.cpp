#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverseList(struct Node *head) {
        Node *temp = nullptr;
        while (head) {
            Node *next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int sum, cy = 0, data1, data2;
        Node *t1 = reverseList(first), *t2 = reverseList(second), *l3 = nullptr, *t3 = nullptr;
        while (t1 != nullptr || t2 != nullptr) {
            if (t1) data1 = t1->data, t1 = t1->next;
            else data1 = 0;
            if (t2) data2 = t2->data, t2 = t2->next;
            else data2 = 0;
            sum = data1 + data2 + cy;
            Node *newnode = new Node(sum % 10);
            cy = sum / 10;
            if (l3 == nullptr)
                l3 = newnode;
            else
                t3->next = newnode;
            t3 = newnode;
        }
        if (cy) {
            Node *newnode = new Node(cy);
            t3->next = newnode;
        }
        return reverseList(l3);
    }
};